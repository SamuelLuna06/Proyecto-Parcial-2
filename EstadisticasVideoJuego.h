#pragma once

#include <vector>

class Jugador;

class EstadisticasVideoJuego {
private:
    std::vector<Jugador*> jugadores;
    int vecesJugado = 0;
    double tiempoJugado = 0.0;

public:
    EstadisticasVideoJuego();

    std::vector<Jugador*> getJugadores() const;
    void addJugador(Jugador* jugador);
    void setTiempoJugado(double tiempoJugado);
    double getTiempoJugado() const;
    void addVecesJugado();
    int getVecesJugado() const;
};
