#pragma once

#include "Jugador.h"

using namespace std;

class Usuario : public Jugador
{
private:
    string nombre;

public:
    Usuario();
    ~Usuario();

    Usuario(string nombre):nombre(nombre){};

    string getNombre() const;
    void setNombre(const string& nombre);

    bool operator == (const Usuario& otro) const {
        return this->nombre == otro.nombre;
    }
};
