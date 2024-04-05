#include "./Usuario.hpp"
#include <iostream>

string Usuario::getNombre() const
{
    return this->nombre;
}

void Usuario::setNombre(const string &nombre)
{
    this->nombre = nombre;
}

string Usuario::getApellido() const
{
    return this->apellido;
}

void Usuario::setApellido(const string &apellido)
{
    this->apellido = apellido;
}

string Usuario::getCorreo() const
{
    return this->correo;
}

void Usuario::setCorreo(const string &correo)
{
    this->correo = correo;
}

string Usuario::getContrasena() const
{
    return this->contrasena;
}

void Usuario::setContrasena(const string &contrasena)
{
    this->contrasena = contrasena;
}