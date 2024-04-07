#pragma once

#include <vector>
#include "VideoJuego.h"
#include "QTableWidget"
#include "QHeaderView"
#include "QVBoxLayout"
#include "QMessageBox"
#include "QPixmap"
#include "QLabel"
#include "QEvent"
#include "QMouseEvent"

using namespace std;

struct Barco
{
    Barco(int fila, int columna) : fila(fila), columna(columna) {};
    int fila;
    int columna;
};

class BatallaNaval : public VideoJuego
{


private:
    QTableWidget *tablero;
    vector<Barco>* barcos;
    QPixmap imgAgua;
    QPixmap imgAguaAcierto;
    QPixmap imgAguaFallo;

    mutable int aciertos;
    mutable int intentos;

    const int TAMANO_TABLERO = 2;
    const int NUMERO_BARCOS = 2;
    const int MAX_INTENTOS = ((TAMANO_TABLERO * TAMANO_TABLERO) / 2) + 1;

public:
    BatallaNaval();
    BatallaNaval(string nombre,string anoLanzamiento,int cantidadJugadores,string desarrollador,string plataforma);
    ~BatallaNaval();

    void iniciarTablero(QWidget* parent);
    void mostrarTablero(QVBoxLayout* layout);
    void colocarBarcos();
    bool acertarBarco(int row, int column) const;
    void mostrarIntentos(QLabel* label) const;

    static void mostrarAlerta(string text);

    void run(QWidget* parent,QVBoxLayout* layout) override;
    void exit() const override;

    QTableWidget * getTablero();
    void setTablero(QTableWidget* tablero);

    vector<Barco>* getBarcos() const;
    void setBarcos(vector<Barco>* barcos);

    void setIntentos(int intentos);
    int getIntentos() const;

    void setAciertos(int aciertos);
    int getAciertos() const;

    int getMaxIntentos() const;
};
