#include "EstadisticasVideoJuego.h"
#include <vector>
using namespace std;

EstadisticasVideoJuego::EstadisticasVideoJuego() {}

void EstadisticasVideoJuego::addJugador(Jugador* jugador){
    auto it = std::find(this->jugadores.begin(),this->jugadores.end(),jugador);
    if(it == this->jugadores.end()){
        this->jugadores.push_back(jugador);
    }
}

vector<Jugador*> EstadisticasVideoJuego::getJugadores() const {
    return this->jugadores;
}

void EstadisticasVideoJuego::setTiempoJugado(double tiempoJugado){
    this->tiempoJugado += tiempoJugado;
}

double EstadisticasVideoJuego::getTiempoJugado() const {
    return this->tiempoJugado;
}

void EstadisticasVideoJuego::addVecesJugado(){
    this->vecesJugado++;
}

int EstadisticasVideoJuego::getVecesJugado() const {
    return this->vecesJugado;
}
