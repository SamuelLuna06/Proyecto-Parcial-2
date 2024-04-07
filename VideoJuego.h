#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <vector>
#include "Categoria.h"
#include "EstadisticasVideoJuego.h"

using namespace std;

class Categoria;
class EstadisticasVideoJuego;

class VideoJuego: public EstadisticasVideoJuego
{
private:
    string nombre;
    int cantidadJugadores;
    string desarrollador;
    string anoLanzamiento;
    string plataforma;
    vector<Categoria*> categorias;


public:
    VideoJuego();
    VideoJuego(string nombre,string anoLanzamiento,int cantidadJugadores,string desarrollador,string plataforma);

    void addCategoria(Categoria* categoria);
    void removeCategoria(Categoria categoria);
    void cleanCategorias();
    vector<Categoria*> getCategorias() const;

    string getNombre() const;
    void setNombre(const string& nombre);

    int getCantidadJugadores() const;
    void setCantidadJugadores(int cantidadJugadores);

    string getDesarrollador() const;
    void setDesarrollador(const string& desarrollador);

    string getAnoLanzamiento() const;
    void setAnoLanzamiento(const string& anoLanzamiento);

    string getPlataforma() const;
    void setPlataforma(const string& plataforma);

    virtual void run() {};
    virtual void run(QWidget* parent,QVBoxLayout* layout) {};

    virtual void exit(){};
    virtual void exit() const {};

    bool operator == (const VideoJuego& otro) const {
        return this->nombre == otro.nombre;
    }
};
