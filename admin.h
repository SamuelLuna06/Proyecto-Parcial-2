#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include "vector"
#include "VideoJuego.h"
#include "juego.h"
#include "QTableWidget"

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

    QTableWidget* buildTableVideoJuegos(vector<VideoJuego*> videoJuegos,Juego* juego,bool activeCheck = true);
    QTableWidget* buildTableCategorias(vector<Categoria*> categoria);

private slots:
    void on_btnJuegosFavoritos_clicked();
    void on_btnJuegos_clicked();
    void on_btnCategorias_clicked();

private:
    Ui::Admin *ui;

};

#endif // ADMIN_H
