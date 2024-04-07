#include "Usuario.h"

Usuario::Usuario()
{

}

Usuario::~Usuario()
{
}

string Usuario::getNombre() const
{
    return this->nombre;
}

void Usuario::setNombre(const string& nombre)
{
    this->nombre = nombre;
}
