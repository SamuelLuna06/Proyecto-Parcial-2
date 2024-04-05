#pragma once

#include <iostream>
#include <vector>
#include "VideoJuego.hpp"

using namespace std;

class VideoJuego;

class Categoria
{
private:
    string nombre;
    string descripcion;
    string tipo;
    vector<VideoJuego *> videojuegos;

public:
    Categoria(string nombre): nombre(nombre){};

    void addVideoJuego(VideoJuego *videojuego);
    vector<VideoJuego *> getVideoJuegos() const;
    
    string getNombre() const;
    void setNombre(const string &nombre);

    string getDescripcion() const;
    void setDescripcion(const string &descripcion);

    string getTipo() const;
    void setTipo(const string &tipo);
};