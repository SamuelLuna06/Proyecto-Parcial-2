#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Ahorcado
{

private:
    int elegirPalabra = 1 + rand() % 5;
    int opcion;
    int intentos;
    int opcionMenu;
    int intentosMaximos;
    bool correcto;
    bool palabraCompleta = false;
    char letra;
    string palabra;
    vector<char> letrasCorrectas;
    vector<string> frutas = {"Cereza", "Manzana", "Pera", "Uva", "Platano"};
    vector<string> profesiones = {"Abogado", "Arquitecto", "Astronauta", "Bombero", "Carpintero"};
    vector<string> paises = {"Colombia", "Argentina", "Brasil", "Chile", "Ecuador"};
    vector<string> deportes = {"Futbol", "Baloncesto", "Voleibol", "Tenis", "Natacion"};
    vector<string> colores = {"Rojo", "Azul", "Verde", "Amarillo", "Naranja"};
    vector<string> mezcla = {"Cereza", "Abogado", "Colombia", "Futbol", "Rojo"};

public:
    Ahorcado() {}

    void jugar()
    {
        switch (opcionMenu)
        {
        case 1:
            palabra = frutas[elegirPalabra];
            break;
        case 2:
            palabra = profesiones[elegirPalabra];
            break;
        case 3:
            palabra = paises[elegirPalabra];
            break;
        case 4:
            palabra = deportes[elegirPalabra];
            break;
        case 5:
            palabra = colores[elegirPalabra];
            break;
        case 6:
            palabra = mezcla[elegirPalabra];
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
        }

        for (auto i = 0; i < palabra.length(); i++)
        {
            cout << "_";
        }
        cout << endl;

        intentos = 6;
        intentosMaximos = 0;

        vector<char> letrasUsadas;

        while (intentos > intentosMaximos and !palabraCompleta)
        {
            cout << "Ingresa una letra:";
            cin >> letra;

            letrasUsadas.push_back(letra);

            for (auto i = 0; i < letrasCorrectas.size(); i++)
            {
                if (letrasCorrectas[i] == palabra[i])
                {
                    palabraCompleta = true;
                }
                else
                {
                    palabraCompleta = false;
                }
            }

            correcto = false;

            for (auto i = 0; i < palabra.length(); i++)
            {
                if (letra == palabra[i])
                {
                    correcto = true;
                    letrasCorrectas.push_back(letra);
                    cout << "La letra " << letra << " esta en la palabra." << endl;
                }
                else
                {
                    intentos--;
                    cout << "La letra " << letra << " no esta en la palabra. Te quedan " << intentos << " intentos." << endl;
                }
            }

            for (auto i = 0; i < palabra.length(); i++)
            {
                if (letra == palabra[i])
                {
                    cout << letra;
                }
                else
                {
                    cout << "_";
                }
            }
            cout << endl;
        }
    }

    void menu()
    {
        do
        {
            cout << "Bienvendio al juego del ahorcado. Elige la categoria que deseas jugar:\n1. Frutas.\n2. Profesiones.\n3. Paises.\n4. Deportes.\n5. Colores.\n6. Mezcla!!\n7. Salir." << endl;
            cin >> opcionMenu;
            switch (opcionMenu)
            {
            case 1:
                cout << "Has elegido la categoria frutas." << endl;
                jugar();
                break;
            case 2:
                cout << "Has elegido la categoria profesiones." << endl;
                jugar();
                break;
            case 3:
                cout << "Has elegido la categoria paises." << endl;
                jugar();
                break;
            case 4:
                cout << "Has elegido la categoria deportes." << endl;
                jugar();
                break;
            case 5:
                cout << "Has elegido la categoria colores." << endl;
                jugar();
                break;
            case 6:
                cout << "Has elegido la categoria mezcla." << endl;
                jugar();
                break;
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
            }
        } while (opcionMenu != 7);
    }
};
