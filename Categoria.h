#pragma once

#include <vector>
#include "VideoJuego.h"

using namespace std;

class VideoJuego;

class Categoria
{
private:
    string nombre;
    string descripcion;
    string tipo;
    vector<VideoJuego*> videojuegos;

public:
    Categoria();
    Categoria(string nombre,string descripcion,string tipo);

    void addVideoJuego(VideoJuego* videojuego);
    vector<VideoJuego*> getVideoJuegos() const;

    string getNombre() const;
    void setNombre(const string& nombre);

    string getDescripcion() const;
    void setDescripcion(const string& descripcion);

    string getTipo() const;
    void setTipo(const string& tipo);

    bool operator == (const Categoria& otro) const {
        return this->nombre == otro.nombre;
    }
};
