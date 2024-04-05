#include "Categoria.hpp"

Categoria::Categoria()
{
}

void Categoria::addVideoJuego(VideoJuego *videojuego)
{
    this->videojuegos.push_back(videojuego);
}

vector<VideoJuego *> Categoria::getVideoJuegos() const
{
    return this->videojuegos;
}

string Categoria::getNombre() const
{
    return this->nombre;
}

void Categoria::setNombre(const string &nombre)
{
    this->nombre = nombre;
}

string Categoria::getDescripcion() const
{
    return this->descripcion;
}

void Categoria::setDescripcion(const string &descripcion)
{
    this->descripcion = descripcion;
}

string Categoria::getTipo() const
{
    return this->tipo;
}

void Categoria::setTipo(const string &tipo)
{
    this->tipo = tipo;
}