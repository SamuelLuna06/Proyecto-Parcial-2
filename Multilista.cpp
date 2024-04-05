#include <iostream>
#include <list>
#include <algorithm>
#include "./Videojuego.hpp"
#include "./Categoria.hpp"

using namespace std;

class Multilista
{
private:
    int opcion;
    list<Categoria> categoriasDeJuegos;

public:
    Multilista() { categoriasDeJuegos = {Categoria("1. Accion."), Categoria("2. Aventura."), Categoria("3. Casuales."), Categoria("4. Deportes."), Categoria("5. Free to play."), Categoria("6. Shooters.")}; };

    void asignarJuegos()
    {
        string opcion1;
        Categoria *categoria = nullptr;

        for (auto i : categoriasDeJuegos)
        {
            cout << categoria->getNombre() << endl;
        }
        cin >> opcion;

        auto it = find_if(categoriasDeJuegos.begin(), categoriasDeJuegos.end(),
                          [opcion1](const Categoria &c)
                          { return c.getNombre() == opcion1; });

        if (it != categoriasDeJuegos.end())
        {
            categoria = &(*it);
        }
        else
        {
            cout << "Categoria no encontrada" << endl;
        }

        switch (opcion)
        {
        case 1:
            categoria->addVideoJuego(new VideoJuego("GTA V"));
            categoria->addVideoJuego(new VideoJuego("Call of Duty"));
            categoria->addVideoJuego(new VideoJuego("Fortnite"));
            break;
        case 2:
            categoria->addVideoJuego(new VideoJuego("The Legend of Zelda"));
            categoria->addVideoJuego(new VideoJuego("Assasins Creed"));
            categoria->addVideoJuego(new VideoJuego("Uncharted"));
            break;
        case 3:
            categoria->addVideoJuego(new VideoJuego("Among Us"));
            categoria->addVideoJuego(new VideoJuego("Candy Crush"));
            categoria->addVideoJuego(new VideoJuego("Plants vs Zombies"));
            break;
        case 4:
            categoria->addVideoJuego(new VideoJuego("FIFA"));
            categoria->addVideoJuego(new VideoJuego("NBA"));
            categoria->addVideoJuego(new VideoJuego("Madden"));
            break;
        case 5:
            categoria->addVideoJuego(new VideoJuego("League of Legends"));
            categoria->addVideoJuego(new VideoJuego("Dota 2"));
            categoria->addVideoJuego(new VideoJuego("Valorant"));
            break;
        case 6:
            categoria->addVideoJuego(new VideoJuego("Call of Duty"));
            categoria->addVideoJuego(new VideoJuego("Counter Strike"));
            categoria->addVideoJuego(new VideoJuego("Overwatch"));
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
        }
    }

    void mostrarJuegos()
    {
        string opcion1;
        Categoria *categoria = nullptr;

        for (auto i : categoriasDeJuegos)
        {
            cout << categoria->getNombre() << endl;
        }
        cin >> opcion;

        auto it = find_if(categoriasDeJuegos.begin(), categoriasDeJuegos.end(),
                          [opcion1](const Categoria &c)
                          { return c.getNombre() == opcion1; });

        if (it != categoriasDeJuegos.end())
        {
            categoria = &(*it);
        }
        else
        {
            cout << "Categoria no encontrada" << endl;
        }

        cout << "Juegos de la categoria " << categoria->getNombre() << ":" << endl;

        for (auto i : categoria->getVideoJuegos())
        {
            cout << i->getNombre() << endl;
        }
    }

    void menu()
    {
        int opcionMenu;
        do
        {
            cout << "Ingrese una opcion:\n1. Mostrar juegos.\n2. Salir." << endl;
            cin >> opcionMenu;
            switch (opcionMenu)
            {
            case 1:
                mostrarJuegos();
                break;
            case 2:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
            }
        } while (opcionMenu != 4);
    }
};