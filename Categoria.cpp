#include "Categoria.h"

Categoria::Categoria()
{
}

Categoria::Categoria(string nombre,string descripcion,string tipo){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipo = tipo;
}

void Categoria::addVideoJuego(VideoJuego* videojuego)
{
    this->videojuegos.push_back(videojuego);
}

vector<VideoJuego*> Categoria::getVideoJuegos() const
{
    return this->videojuegos;
}

string Categoria::getNombre() const
{
    return this->nombre;
}

void Categoria::setNombre(const string& nombre)
{
    this->nombre = nombre;
}

string Categoria::getDescripcion() const
{
    return this->descripcion;
}

void Categoria::setDescripcion(const string& descripcion)
{
    this->descripcion = descripcion;
}

string Categoria::getTipo() const
{
    return this->tipo;
}

void Categoria::setTipo(const string& tipo)
{
    this->tipo = tipo;
}
