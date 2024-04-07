#include "juego.h"
#include "ui_juego.h"
#include "BatallaNaval.h"
#include "Ahorcado.h"
#include "bd.h"
#include "admin.h"
#include <chrono>

Juego::Juego(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
}

Juego::~Juego()
{
    delete ui;
}

void Juego::setVideoJuego(VideoJuego* videoJuego){
    this->videoJuego = videoJuego;
}

void Juego::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    this->ui->pushButton->hide();

    string nombreJuego = this->videoJuego->getNombre();
    this->videoJuego->addVecesJugado();
    if (nombreJuego == "Batalla Naval") {
        this->signalJuegoBatallaNaval();
    } else if (nombreJuego == "Ahorcado") {
       this->videoJuego->run(this,this->ui->verticalLayout);
    }
}

void Juego::closeEvent(QCloseEvent *event){
    QMainWindow::closeEvent(event);

    Admin *admin = new Admin;
    admin->show();
    admin->setVisible(true);
}

void Juego::signalJuegoBatallaNaval(std::chrono::steady_clock::time_point tiempoIncial){

    BatallaNaval batallaNaval = *(static_cast<BatallaNaval*>(this->videoJuego));
    batallaNaval.run(this, this->ui->verticalLayout);

    Usuario* usuario = BD::instancia().getCurrentUsuario();


    connect(batallaNaval.getTablero(), &QTableWidget::cellClicked, this, [this,usuario,batallaNaval,tiempoIncial](int row, int column) {
        if(batallaNaval.acertarBarco(row, column)){
            BatallaNaval::mostrarAlerta("Has destruido un barco enemigo! " + usuario->getNombre());
        }else{
            BatallaNaval::mostrarAlerta("Has fallado, el disparo ha dado en el agua! " + usuario->getNombre());
        }

        batallaNaval.mostrarIntentos(this->ui->label);
        if(batallaNaval.getAciertos() == (*batallaNaval.getBarcos()).size()){
            BatallaNaval::mostrarAlerta("Has ganado! " + usuario->getNombre());
            batallaNaval.exit();
            this->ui->pushButton->show();
            this->ui->label->setText("");
            auto tiempoFinal = std::chrono::steady_clock::now();
            this->videoJuego->setTiempoJugado(std::chrono::duration_cast<std::chrono::minutes>(tiempoFinal - tiempoIncial).count());
        }else if(batallaNaval.getIntentos() == batallaNaval.getMaxIntentos()){
            BatallaNaval::mostrarAlerta("Has alcanzado el limite de intentos. Vuelve a intentarlo " + usuario->getNombre());
            batallaNaval.exit();
            this->ui->pushButton->show();
            this->ui->label->setText("");
            auto tiempoFinal = std::chrono::steady_clock::now();
            this->videoJuego->setTiempoJugado(std::chrono::duration_cast<std::chrono::minutes>(tiempoFinal - tiempoIncial).count());
        }
    });
}


void Juego::on_pushButton_clicked()
{
    this->ui->pushButton->hide();
    string nombreJuego = this->videoJuego->getNombre();
    this->videoJuego->addVecesJugado();
    this->videoJuego->addJugador(BD::instancia().getCurrentUsuario());
    if (nombreJuego == "Batalla Naval") {
        this->signalJuegoBatallaNaval(std::chrono::steady_clock::now());
    } else if (nombreJuego == "Ahorcado") {
        this->videoJuego->run(this,this->ui->verticalLayout);
    }
}

