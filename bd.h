#ifndef BD_H
#define BD_H

#include <vector>
#include "Usuario.h"

class BD
{
private :
    BD();
    BD(const BD&) = delete;
    BD& operator=(const BD&) = delete;

    vector<VideoJuego*> videoJuegos;
    vector<Categoria*> categorias;
    vector<Usuario*> usuarios;
    Usuario* currentUsuario;

public:
    static BD& instancia() {
        static BD instancia;
        return instancia;
    }

    Usuario* addUsuario(Usuario* usuario);
    vector<Usuario*> getUsuarios() const;

    void addCategoria(Categoria* categoria);
    vector<Categoria*> getCategorias() const;

    void setCurrentUsuario(Usuario* usuario);
    Usuario* getCurrentUsuario() const;

    vector<VideoJuego*> getVideoJuegos() const;
    vector<VideoJuego*> ordenarPorTitulo(bool invert = false);
    vector<VideoJuego*> ordenarPorFecha(bool invert = false);
    vector<VideoJuego*> ordenarPorVecesJugado(bool invert = false);
    vector<VideoJuego*> filtrarPorPlataforma(const string &plataforma);
};

#endif // BD_H
