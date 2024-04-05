#include <iostream>
#include "./VideoJuego.hpp"
using namespace std;

VideoJuego::VideoJuego()
{
}

void VideoJuego::addCategoria(Categoria *categoria)
{
    this->categorias.push_back(categoria);
}

string VideoJuego::getNombre() const
{
    return this->nombre;
}

void VideoJuego::setNombre(const string &nombre)
{
    this->nombre = nombre;
}

int VideoJuego::getCantidadJugadores() const
{
    return this->cantidadJugadores;
}

void VideoJuego::setCantidadJugadores(int cantidadJugadores)
{
    this->cantidadJugadores = cantidadJugadores;
}

string VideoJuego::getDesarrollador() const
{
    return this->desarrollador;
}

void VideoJuego::setDesarrollador(const string &desarrollador)
{
    this->desarrollador = desarrollador;
}

string VideoJuego::getAnoLanzamiento() const
{
    return this->anoLanzamiento;
}

void VideoJuego::setAnoLanzamiento(const string &anoLanzamiento)
{
    this->anoLanzamiento = anoLanzamiento;
}

string VideoJuego::getPlataforma() const
{
    return this->plataforma;
}

void VideoJuego::setPlataforma(const string &plataforma)
{
    this->plataforma = plataforma;
}

void VideoJuego::removeCategoria(Categoria categoria)
{
    for (int i = 0; i < this->categorias.size(); i++)
    {
        if ((*this->categorias[i]).getNombre() == categoria.getNombre())
        {
            this->categorias.erase(this->categorias.begin() + i);
            break;
        }
    }
}

void VideoJuego::cleanCategorias()
{
    this->categorias.clear();
}