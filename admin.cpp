#include "admin.h"
#include "ui_admin.h"
#include "utils.h"
#include "bd.h"
#include "juego.h"
#include "QComboBox"
#include "QHeaderView"
#include "QCheckBox"
#include "QMessageBox"
#include "QLineEdit"

Admin::Admin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}


QTableWidget* Admin::buildTableVideoJuegos(vector<VideoJuego*> videoJuegos,Juego *juego,bool activeCheck){

    vector<VideoJuego*> videoJuegosFavoritos =  BD::instancia().getCurrentUsuario()->getVideoJuegosFavoritos();
    QTableWidget *tableJuegos = new QTableWidget;
    tableJuegos->setColumnCount(11);
    tableJuegos->setHorizontalHeaderLabels(QStringList() << "" << "Nombre" << "Num. Jugadores" << "Desarrollador" << "Año Lanzamiento" << "Plataforma" << "Tiempo Jugado Min" << "Veces Jugado" << "Categorias"<< "Favorito" <<"");

    int rowCount = static_cast<int>(videoJuegos.size());
    tableJuegos->setRowCount(rowCount);

    for(int i = 0; i < rowCount; i++) {
        VideoJuego* videoJuego = videoJuegos[i];

        QCheckBox *checkBox = new QCheckBox;
        QWidget* widget = new QWidget();
        QHBoxLayout* layout = new QHBoxLayout(widget);
        layout->setAlignment(Qt::AlignCenter);
        layout->addWidget(checkBox);
        widget->setLayout(layout);

        tableJuegos->setCellWidget(i,0,widget);
        if(activeCheck){
            connect(checkBox,&QCheckBox::clicked,this,[tableJuegos,videoJuego,this](bool check){
                tableJuegos->setDisabled(true);
                this->ui->btnAddClass->setDisabled(false);
                this->ui->btnAddClass->setProperty("data",QVariant::fromValue(videoJuego));
            });
        }

        tableJuegos->setItem(i,1,new QTableWidgetItem(QString::fromStdString(videoJuego->getNombre())));
        tableJuegos->setItem(i,2,new QTableWidgetItem(QString::number(videoJuego->getCantidadJugadores())));
        tableJuegos->setItem(i,3,new QTableWidgetItem(QString::fromStdString(videoJuego->getDesarrollador())));
        tableJuegos->setItem(i,4,new QTableWidgetItem(QString::fromStdString(videoJuego->getAnoLanzamiento())));
        tableJuegos->setItem(i,5,new QTableWidgetItem(QString::fromStdString(videoJuego->getPlataforma())));
        tableJuegos->setItem(i,6,new QTableWidgetItem(QString::number(videoJuego->getTiempoJugado())));
        tableJuegos->setItem(i,7,new QTableWidgetItem(QString::number(videoJuego->getVecesJugado())));

        QComboBox *listaCategorias = new QComboBox ;
        for(auto categoria:videoJuego->getCategorias()){
            listaCategorias->addItem(QString::fromStdString(categoria->getNombre()));
        }
        tableJuegos->setCellWidget(i,8,listaCategorias);

        QCheckBox *checkBoxFavorito = new QCheckBox;
        QWidget* widgetFavorito = new QWidget();
        QHBoxLayout* layoutFavorito = new QHBoxLayout(widgetFavorito);
        layoutFavorito->setAlignment(Qt::AlignCenter);
        layoutFavorito->addWidget(checkBoxFavorito);
        widgetFavorito->setLayout(layoutFavorito);
        tableJuegos->setCellWidget(i,9,checkBoxFavorito);

        auto it = std::find(videoJuegosFavoritos.begin(),videoJuegosFavoritos.end(),videoJuego);
        checkBoxFavorito->setChecked(it != videoJuegosFavoritos.end());
        connect(checkBoxFavorito,&QCheckBox::clicked,this,[videoJuego](bool check){
            if(check){
                BD::instancia().getCurrentUsuario()->addVideoJuegoFavorito(videoJuego);
            } else {
                BD::instancia().getCurrentUsuario()->removeVideoJuegoFavorito(videoJuego);
            }
        });

        QPushButton* btnRun = new QPushButton;
        btnRun->setText("Jugar!");
        connect(btnRun, &QPushButton::clicked,this, [videoJuego,juego,this]() {
            juego->setVideoJuego(videoJuego);
            juego->show();
            juego->setVisible(true);

            this->hide();
            this->setVisible(false);
        });
        tableJuegos->setCellWidget(i,10,btnRun);
    }

    tableJuegos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableJuegos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    return tableJuegos;
}


QTableWidget* Admin::buildTableCategorias(vector<Categoria*> categorias){
    QTableWidget *tableCategorias = new QTableWidget;
    tableCategorias->setColumnCount(5);
    tableCategorias->setHorizontalHeaderLabels(QStringList() << "" << "Nombre" << "Descripcion" << "Tipo" << "videoJuegos");

    int rowCount = static_cast<int>(categorias.size());
    tableCategorias->setRowCount(rowCount);

    for(int i = 0; i < rowCount; i++) {
        Categoria* categoria = categorias[i];

        QCheckBox *checkBox = new QCheckBox;
        QWidget* widget = new QWidget();
        QHBoxLayout* layout = new QHBoxLayout(widget);
        layout->setAlignment(Qt::AlignCenter);
        layout->addWidget(checkBox);
        widget->setLayout(layout);

        tableCategorias->setCellWidget(i,0,widget);
        connect(checkBox,&QCheckBox::clicked,this,[tableCategorias,categoria,this](bool check){
            tableCategorias->setDisabled(true);
            this->ui->btnAddClass->setDisabled(false);
            this->ui->btnAddClass->setProperty("data",QVariant::fromValue(categoria));
        });

        tableCategorias->setItem(i,1,new QTableWidgetItem(QString::fromStdString(categoria->getNombre())));
        tableCategorias->setItem(i,2,new QTableWidgetItem(QString::fromStdString(categoria->getDescripcion())));
        tableCategorias->setItem(i,3,new QTableWidgetItem(QString::fromStdString(categoria->getTipo())));

        QComboBox *listaJuegos = new QComboBox ;
        for(auto videoJuego:categoria->getVideoJuegos()){
            listaJuegos->addItem(QString::fromStdString(videoJuego->getNombre()));
        }
        tableCategorias->setCellWidget(i,4,listaJuegos);
    }

    tableCategorias->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableCategorias->setEditTriggers(QAbstractItemView::NoEditTriggers);
    return tableCategorias;
}

void Admin::on_btnJuegosFavoritos_clicked()
{

    this->ui->textNameFrame->setText("Lista de Juegos Favoritos");
    Juego* juego = new Juego;
    Utils::limpiarLayout(this->ui->horizontalLayout);
    Utils::limpiarLayout(this->ui->horizontalLayouSorts);
    Utils::limpiarLayout(this->ui->verticalLayoutFilter);
    this->ui->btnAddClass->setVisible(false);
    this->ui->btnAddClass->hide();
    this->ui->listClassRef->clear();

    vector<VideoJuego*> videoJuegos = BD::instancia().getCurrentUsuario()->getVideoJuegosFavoritos();
    QTableWidget* tableJuegos = this->buildTableVideoJuegos(videoJuegos,juego,false);
    this->ui->horizontalLayout->addWidget(tableJuegos);
}

void Admin::on_btnJuegos_clicked()
{

    Juego* juego = new Juego;
    Utils::limpiarLayout(this->ui->horizontalLayout);
    Utils::limpiarLayout(this->ui->horizontalLayouSorts);
    Utils::limpiarLayout(this->ui->verticalLayoutFilter);
    this->ui->btnAddClass->setVisible(true);
    this->ui->btnAddClass->show();

    this->ui->textNameFrame->setText("Lista de Juegos");
    this->ui->listClassRef->clear();

    std::unique_ptr<bool> invertFilterTitulo(new bool(false));
    QPushButton *btnSortTitulo = new QPushButton;
    btnSortTitulo->setText("Ordenar por titulo");
    connect(btnSortTitulo, &QPushButton::clicked, this, [this, juego, invertFilterTitulo = std::move(invertFilterTitulo)]() mutable {
        QTableWidget* tableJuegos = this->buildTableVideoJuegos(BD::instancia().ordenarPorTitulo(*invertFilterTitulo), juego);
        Utils::limpiarLayout(this->ui->horizontalLayout);
        this->ui->horizontalLayout->addWidget(tableJuegos);
        *invertFilterTitulo = !(*invertFilterTitulo);
    });

    std::unique_ptr<bool> invertFilterFecha(new bool(false));
    QPushButton *btnSortFecha = new QPushButton;
    btnSortFecha->setText("Ordenar por Fecha");
    connect(btnSortFecha,&QPushButton::clicked,this,[this,juego,invertFilterFecha = std::move(invertFilterFecha)]() mutable{
        QTableWidget* tableJuegos  = this->buildTableVideoJuegos(BD::instancia().ordenarPorFecha(*invertFilterFecha),juego) ;
        Utils::limpiarLayout(this->ui->horizontalLayout);
        this->ui->horizontalLayout->addWidget(tableJuegos);
        *invertFilterFecha = !(*invertFilterFecha);
    });

    std::unique_ptr<bool> invertFilerVecesJugado(new bool(false));
    QPushButton *btnSortVecesJugado = new QPushButton;
    btnSortVecesJugado->setText("Ordenar por Veces Jugado");
    connect(btnSortVecesJugado,&QPushButton::clicked,this,[this,juego,invertFilerVecesJugado = std::move(invertFilerVecesJugado)]() mutable{
        QTableWidget* tableJuegos  = this->buildTableVideoJuegos(BD::instancia().ordenarPorVecesJugado(*invertFilerVecesJugado),juego) ;
        Utils::limpiarLayout(this->ui->horizontalLayout);
        this->ui->horizontalLayout->addWidget(tableJuegos);
        *invertFilerVecesJugado = !(*invertFilerVecesJugado);
    });

    QLineEdit *inputLine = new QLineEdit(this);
    inputLine->setPlaceholderText("Introduce tu texto aquí");
    QPushButton *btnFilter = new QPushButton;
    btnFilter->setText("Buscar");
    connect(btnFilter,&QPushButton::clicked,this,[this,inputLine,juego](){
        vector<VideoJuego*> filter = BD::instancia().filtrarPorPlataforma(inputLine->text().toStdString());
        QTableWidget* tableJuegos  = this->buildTableVideoJuegos(filter,juego) ;
        Utils::limpiarLayout(this->ui->horizontalLayout);
        this->ui->horizontalLayout->addWidget(tableJuegos);
    });

    this->ui->horizontalLayouSorts->addWidget(btnSortTitulo);
    this->ui->horizontalLayouSorts->addWidget(btnSortFecha);
    this->ui->horizontalLayouSorts->addWidget(btnSortVecesJugado);
    this->ui->verticalLayoutFilter->addWidget(inputLine);
    this->ui->verticalLayoutFilter->addWidget(btnFilter);

    vector<VideoJuego*> videoJuegos = BD::instancia().getVideoJuegos();
    QTableWidget* tableJuegos = this->buildTableVideoJuegos(videoJuegos,juego);
    this->ui->horizontalLayout->addWidget(tableJuegos);

    vector<Categoria*> categorias = BD::instancia().getCategorias();
    QComboBox *listaCategorias = this->ui->listClassRef;
    for(int i = 0;i <categorias.size() ;i++){
        Categoria* categoria = categorias[i];
        listaCategorias->addItem(QString::fromStdString(categoria->getNombre()));
        listaCategorias->setItemData(i,QVariant::fromValue(categoria));
    }
    this->ui->btnAddClass->setDisabled(true);

    disconnect(this->ui->btnAddClass,&QPushButton::clicked,nullptr,nullptr);
    connect(this->ui->btnAddClass,&QPushButton::clicked,this,[this,juego](){
        VideoJuego* videoJuego = this->ui->btnAddClass->property("data").value<VideoJuego*>();
        videoJuego->addCategoria(this->ui->listClassRef->currentData().value<Categoria*>());

        Utils::limpiarLayout(this->ui->horizontalLayout);
        this->ui->horizontalLayout->addWidget(this->buildTableVideoJuegos(BD::instancia().getVideoJuegos(),juego));
    });
}

void Admin::on_btnCategorias_clicked()
{

    this->ui->textNameFrame->setText("Lista de Categorias");
    this->ui->listClassRef->clear();
    Utils::limpiarLayout(this->ui->horizontalLayout);
    Utils::limpiarLayout(this->ui->horizontalLayouSorts);
    Utils::limpiarLayout(this->ui->verticalLayoutFilter);
    this->ui->btnAddClass->setVisible(true);
    this->ui->btnAddClass->show();

    disconnect(this->ui->btnAddClass,&QPushButton::clicked,0,0);

    vector<VideoJuego*> videoJuegos = BD::instancia().getVideoJuegos();
    QComboBox *listaJuegos = this->ui->listClassRef;
    for(int i = 0;i < videoJuegos.size() ;i++){
        VideoJuego* videoJuego = videoJuegos[i];
        listaJuegos->addItem(QString::fromStdString(videoJuego->getNombre()));
        listaJuegos->setItemData(i,QVariant::fromValue(videoJuego));
    }
    this->ui->btnAddClass->setDisabled(true);

    vector<Categoria*> categorias = BD::instancia().getCategorias();
    QTableWidget* tableCategorias = buildTableCategorias(categorias);
    this->ui->horizontalLayout->addWidget(tableCategorias);

    disconnect(this->ui->btnAddClass,&QPushButton::clicked,nullptr,nullptr);
    connect(this->ui->btnAddClass,&QPushButton::clicked,this,[this](){
        Categoria* categoria = this->ui->btnAddClass->property("data").value<Categoria*>();
        categoria->addVideoJuego(this->ui->listClassRef->currentData().value<VideoJuego*>());
        Utils::limpiarLayout(this->ui->horizontalLayout);
        this->ui->horizontalLayout->addWidget(this->buildTableCategorias(BD::instancia().getCategorias()));
    });
}


