#include "Jugador.h"


void Jugador::addVideoJuegoFavorito(VideoJuego* videoJuegoFavorito){
    auto it = find(this->videojuegosFavoritos.begin(),this->videojuegosFavoritos.end(),videoJuegoFavorito);
    if (it == this-> videojuegosFavoritos.end()) {
        this->videojuegosFavoritos.push_back(videoJuegoFavorito);
    }
}

vector<VideoJuego*> Jugador::getVideoJuegosFavoritos() const {
    return this->videojuegosFavoritos;
}

void Jugador::removeVideoJuegoFavorito(VideoJuego* videoJuegoFavorito){
    auto it = find(this->videojuegosFavoritos.begin(),this->videojuegosFavoritos.end(),videoJuegoFavorito);
    if (it != this-> videojuegosFavoritos.end()) {
        this->videojuegosFavoritos.erase(it);
    }
}
