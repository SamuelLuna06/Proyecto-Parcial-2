#include "QCoreApplication"
#include "BatallaNaval.h"

BatallaNaval::BatallaNaval()
{
    this->barcos = nullptr;
    this->intentos = 0;
    this->aciertos = 0;
    this->imgAgua = QPixmap(":/agua.jpg");
    this->imgAguaAcierto = QPixmap(":/agua-check.jpg");
    this->imgAguaFallo = QPixmap(":/agua-fail.jpg");
}

BatallaNaval::BatallaNaval(string nombre,string anoLanzamiento,int cantidadJugadores,string desarrollador,string plataforma)
    : VideoJuego(nombre,anoLanzamiento,cantidadJugadores,desarrollador,plataforma){
    this->barcos = nullptr;
    this->intentos = 0;
    this->aciertos = 0;
    this->imgAgua = QPixmap(":/agua.jpg");
    this->imgAguaAcierto = QPixmap(":/agua-check.jpg");
    this->imgAguaFallo = QPixmap(":/agua-fail.jpg");
}

BatallaNaval::~BatallaNaval()
{
}

void BatallaNaval::iniciarTablero(QWidget* parent)
{
    this->tablero = new QTableWidget(this->TAMANO_TABLERO,this->TAMANO_TABLERO,parent);
    for (int row = 0; row < this->TAMANO_TABLERO; ++row) {
        for (int col = 0; col < this->TAMANO_TABLERO; ++col) {
            QLabel *label = new QLabel;
            label->setPixmap(this->imgAgua);
            label->setScaledContents(true);
            label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            this->tablero->setCellWidget(row,col,label);
        }
    }
}

void BatallaNaval::mostrarTablero(QVBoxLayout* layout)
{
    this->tablero->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->tablero->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->tablero->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->tablero->setCursor(Qt::PointingHandCursor);
    layout->addWidget(this->tablero);
}

void BatallaNaval::colocarBarcos()
{
    this->barcos = new vector<Barco>;
    for (int i = 0; i < NUMERO_BARCOS; ++i)
    {
        srand(i);
        Barco barco(rand() % TAMANO_TABLERO, rand() % TAMANO_TABLERO);
        this->barcos->push_back(barco);
    }
}

bool BatallaNaval::acertarBarco(int row, int column) const
{
    intentos++;
    bool assert = false;
    for (Barco barcoTablero : *this->barcos)
    {
        if (barcoTablero.fila == row && barcoTablero.columna == column)
        {
            assert = true;
            aciertos++;
            break;
        }
    }
    QLabel *label = new QLabel;
    label->setPixmap(assert ? this->imgAguaAcierto:this->imgAguaFallo);
    label->setScaledContents(true);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->tablero->setCellWidget(row,column,label);
    return assert;
}

void BatallaNaval::mostrarIntentos(QLabel* label) const {
    label->setText(QString("Intentos %1 / %2").arg(this->intentos).arg(this->MAX_INTENTOS));
}

void BatallaNaval::mostrarAlerta(string text) {
    QMessageBox msg;
    msg.setText(text.c_str());
    msg.exec();
}

void BatallaNaval::run(QWidget* parent,QVBoxLayout* layout)
{
    this->iniciarTablero(parent);
    this->colocarBarcos();
    this->mostrarTablero(layout);
}

void BatallaNaval::exit() const {
    this->tablero->deleteLater();
}

QTableWidget * BatallaNaval::getTablero(){
    return this->tablero;
}

void BatallaNaval::setTablero(QTableWidget* tablero){
    this->tablero = tablero;
}

vector<Barco>* BatallaNaval::getBarcos() const {
    return this->barcos;
}

void BatallaNaval::setBarcos(std::vector<Barco>* barcos) {
    this->barcos = barcos;
}

void BatallaNaval::setAciertos(int aciertos){
    this->aciertos = aciertos;
}

int BatallaNaval::getAciertos() const{
    return this->aciertos;
}

void BatallaNaval::setIntentos(int intentos){
    this->intentos = intentos;
}

int BatallaNaval::getIntentos() const{
    return this->intentos;
}

int BatallaNaval::getMaxIntentos() const{
    return this->MAX_INTENTOS;
}
