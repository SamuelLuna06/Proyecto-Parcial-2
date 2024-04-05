#include <iostream>
using namespace std;

class Usuario
{
private:
    string nombre;
    string apellido;
    string correo;
    string contrasena;

public:
    Usuario();
    ~Usuario();

    string getNombre() const;
    void setNombre(const string &nombre);
    
    string getApellido() const;
    void setApellido(const string &apellido);
    
    string getCorreo() const;
    void setCorreo(const string &correo);
    
    string getContrasena() const;
    void setContrasena(const string &contrasena);
};