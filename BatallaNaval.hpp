#pragma once

#include <iostream>
#include <vector>
#include "VideoJuego.hpp"
#include "Runable.hpp"
using namespace std;

struct Barco
{
    Barco(int file, int columna) : fila(fila), columna(columna){};
    int fila;
    int columna;
};

class BatallaNaval : public VideoJuego
{
private:
    vector<vector<char>> tablero;
    vector<Barco> barcos;
    const int TAMANO_TABLERO = 5;
    const int NUMERO_BARCOS = 3;

public:
    BatallaNaval();
    ~BatallaNaval();
    void iniciarTablero();
    void mostrarTablero();
    void colocarBarcos();
    bool acertarBarco(Barco barco);
    void run() override;
};