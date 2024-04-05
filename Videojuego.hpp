#pragma once

#include <iostream>
#include <vector>
#include "Categoria.hpp"
using namespace std;

class Categoria;

class VideoJuego
{
private:
    string nombre;
    int cantidadJugadores;
    string desarrollador;
    string anoLanzamiento;
    string plataforma;
    vector<Categoria *> categorias;

public:
    VideoJuego(string nombre):nombre(nombre){};

    void addCategoria(Categoria *categoria);
    void removeCategoria(Categoria categoria);
    void cleanCategorias();

    string getNombre() const;
    void setNombre(const string &nombre);

    int getCantidadJugadores() const;
    void setCantidadJugadores(int cantidadJugadores);

    string getDesarrollador() const;
    void setDesarrollador(const string &desarrollador);

    string getAnoLanzamiento() const;
    void setAnoLanzamiento(const string &anoLanzamiento);

    string getPlataforma() const;
    void setPlataforma(const string &plataforma);

    virtual void run() {};
};