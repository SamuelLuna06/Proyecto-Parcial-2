#include "parcial2.h"
#include "./ui_parcial2.h"
#include "Usuario.h"
#include "bd.h"
#include "admin.h"

using namespace std;

Parcial2::Parcial2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Parcial2)
{
    ui->setupUi(this);
}

Parcial2::~Parcial2()
{
    delete ui;
}

void Parcial2::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
}

void Parcial2::on_btnLogin_clicked()
{

    Usuario* usuario =  BD::instancia().addUsuario(new Usuario(this->ui->inputUsername->toPlainText().toStdString()));
    BD::instancia().setCurrentUsuario(usuario);

    Admin *admin = new Admin;
    admin->show();
    admin->setVisible(true);

    this->hide();
    this->setVisible(false);
}

