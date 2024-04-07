#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

class Ahorcado
{

private:
    int elegirPalabra;
    int opcion;
    int intentos;
    int opcionMenu;
    int intentosMaximos;
    bool correcto;
    bool palabraCompleta = false;
    char letra;
    string palabra;
    vector<char> letrasCorrectas;
    vector<string> frutas = {"cereza", "manzana", "pera", "uva", "platano"};
    vector<string> profesiones = {"abogado", "arquitecto", "astronauta", "bombero", "carpintero"};
    vector<string> paises = {"colombia", "argentina", "brasil", "chile", "ecuador"};
    vector<string> deportes = {"futbol", "baloncesto", "voleibol", "tenis", "natacion"};
    vector<string> colores = {"rojo", "azul", "verde", "amarillo", "naranja"};
    vector<string> mezcla = {"cereza", "abogado", "colombia", "futbol", "rojo"};

public:
    Ahorcado() {}

    void jugar()
    {
        srand(time(NULL));
        elegirPalabra = 1 + rand() % 5;
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

        for (std::string::size_type i; i < palabra.length(); i++)
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

            correcto = false;
            bool letraEncontrada = false;
            letra = tolower(letra);

            for (std::string::size_type i = 0; i < palabra.length(); i++)
            {
                if (letra == tolower(palabra[i]))
                {
                    correcto = true;
                    letraEncontrada = true;
                    letrasCorrectas.push_back(letra);
                    cout << "La letra " << letra << " esta en la palabra." << endl;
                }
            }

            if (!letraEncontrada)
            {
                intentos--;
                cout << "La letra " << letra << " no esta en la palabra. Te quedan " << intentos << " intentos." << endl;
            }

            string palabraUsuario = "";

            for (std::string::size_type i = 0; i < palabra.length(); i++)
            {
                if (std::find(letrasCorrectas.begin(), letrasCorrectas.end(), static_cast<char>(tolower(palabra[i]))) != letrasCorrectas.end())
                {
                    palabraUsuario += palabra[i];
                    cout << palabra[i];
                }
                else
                {
                    palabraUsuario += "_";
                    cout << "_";
                }
            }
            cout << endl;

            if (palabraUsuario == palabra)
            {
                palabraCompleta = true;
                cout << "Felicidades, has adivinado la palabra!!" << endl;
            }
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
