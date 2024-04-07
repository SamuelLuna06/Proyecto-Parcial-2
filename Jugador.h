#pragma once

#include <vector>
#include "VideoJuego.h"
using namespace std;

class VideoJuego;

class Jugador {
private:
    vector<VideoJuego*> videojuegosFavoritos;

public:
    void addVideoJuegoFavorito(VideoJuego* videojuegoFavorito);
    void removeVideoJuegoFavorito(VideoJuego* videoJuegoFavorito);
    vector<VideoJuego*> getVideoJuegosFavoritos() const;
};
