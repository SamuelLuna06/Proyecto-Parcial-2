#include "Ahorcado.h"

Ahorcado::Ahorcado() {}

Ahorcado::Ahorcado(string nombre,string anoLanzamiento,int cantidadJugadores,string desarrollador,string plataforma)
    : VideoJuego(nombre,anoLanzamiento,cantidadJugadores,desarrollador,plataforma){
}

void Ahorcado::run(QWidget* parent,QVBoxLayout* layout){
    this->verticalLayout = layout;
    this->menu();
}

void Ahorcado::exit() const {
}
