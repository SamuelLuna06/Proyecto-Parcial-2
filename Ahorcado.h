#pragma once

#include "VideoJuego.h"
#include <QDebug>
#include <QString>
#include <QVBoxLayout>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "QLabel"
#include <iostream>
using namespace std;

class Ahorcado : public VideoJuego
{
private:
    QVBoxLayout *verticalLayout;
    int elegirPalabra;
    int intentos;
    int opcionMenu;
    int intentosMaximos;
    bool correcto;
    bool palabraCompleta = false;
    char letra;
    QString palabra;
    std::vector<char> letrasCorrectas;
    std::vector<QString> frutas = {"cereza", "manzana", "pera", "uva", "platano"};
    std::vector<QString> profesiones = {"abogado", "arquitecto", "astronauta", "bombero", "carpintero"};
    std::vector<QString> paises = {"colombia", "argentina", "brasil", "chile", "ecuador"};
    std::vector<QString> deportes = {"futbol", "baloncesto", "voleibol", "tenis", "natacion"};
    std::vector<QString> colores = {"rojo", "azul", "verde", "amarillo", "naranja"};
    std::vector<QString> mezcla = {"cereza", "abogado", "colombia", "futbol", "rojo"};

public:
    Ahorcado();
    Ahorcado(string nombre,string anoLanzamiento,int cantidadJugadores,string desarrollador,string plataforma);
    void run(QWidget* parent,QVBoxLayout* layout) override;
    void exit() const override;

    void crearMuneco(int intentos)
    {
        QString message;
        switch (intentos)
        {
        case 6:
            message = "    _________\n   |        |\n   |         \n   |  \n   |  \n   |  \n_______\n";
            break;
        case 5:
            message = "    _________\n   |        |\n   |        O\n   |  \n   |  \n   |  \n_______\n";
            break;
        case 4:
            message = "    _________\n   |        |\n   |        O\n   |       /|\n   |  \n   |  \n_______\n";
            break;
        case 3:
            message = "    _________\n   |        |\n   |        O\n   |       /|\\n   |  \n   |  \n_______\n";
            break;
        case 2:
            message = "    _________\n   |        |\n   |        O\n   |       /|\\n   |       /\n   |  \n_______\n";
            break;
        case 1:
            message = "    _________\n   |        |\n   |        O\n   |       /|\\n   |       / \\\n   |  \n_______\n";
            break;
        default:
            message = "Opcion no valida.\n";
            break;
        }
        // Agrega el mensaje al QVBoxLayout
        verticalLayout->addWidget(new QLabel(message));
    }

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
            qDebug() << "Opcion no valida.";
            break;
        }

        for (int i = 0; i < palabra.length(); i++)
        {
            qDebug() << "_";
        }

        intentos = 6;
        intentosMaximos = 0;

        std::vector<char> letrasUsadas;

        while (intentos > intentosMaximos && !palabraCompleta)
        {
            qDebug() << "Ingresa una letra:";
            std::cin >> letra;

            letrasUsadas.push_back(letra);

            correcto = false;
            bool letraEncontrada = false;
            letra = tolower(letra);

            for (int i = 0; i < palabra.length(); i++)
            {
                if (letra == tolower(palabra.toStdString()[i]))
                {
                    correcto = true;
                    letraEncontrada = true;
                    letrasCorrectas.push_back(letra);
                    qDebug() << "La letra " << letra << " esta en la palabra.";
                }
            }

            if (!letraEncontrada)
            {
                crearMuneco(intentos);
                intentos--;
                qDebug() << "La letra " << letra << " no esta en la palabra. Te quedan " << intentos << " intentos.";
            }

            QString palabraUsuario = "";
            for (int i = 0; i < palabra.length(); i++)
            {
                if (std::find(letrasCorrectas.begin(), letrasCorrectas.end(), static_cast<char>(std::tolower(palabra.toStdString()[i]))) != letrasCorrectas.end())
                {
                    palabraUsuario += palabra[i];
                    qDebug() << palabra[i];
                }
                else
                {
                    palabraUsuario += "_";
                    qDebug() << "_";
                }
            }

            if (palabraUsuario == palabra)
            {
                palabraCompleta = true;
                qDebug() << "Felicidades, has adivinado la palabra!!";
            }
        }
    }

    void menu()
    {
        do
        {
            qDebug() << "Bienvendio al juego del ahorcado. Elige la categoria que deseas jugar:\n1. Frutas.\n2. Profesiones.\n3. Paises.\n4. Deportes.\n5. Colores.\n6. Mezcla!!\n7. Salir.";
            std::cin >> opcionMenu;
            switch (opcionMenu)
            {
            case 1:
                qDebug() << "Has elegido la categoria frutas.";
                jugar();
                break;
            case 2:
                qDebug() << "Has elegido la categoria profesiones.";
                jugar();
                break;
            case 3:
                qDebug() << "Has elegido la categoria paises.";
                jugar();
                break;
            case 4:
                qDebug() << "Has elegido la categoria deportes.";
                jugar();
                break;
            case 5:
                qDebug() << "Has elegido la categoria colores.";
                jugar();
                break;
            case 6:
                qDebug() << "Has elegido la categoria mezcla.";
                jugar();
                break;
            case 7:
                qDebug() << "Saliendo...";
                break;
            default:
                qDebug() << "Opcion no valida.";
                break;
            }
        } while (opcionMenu != 7);
    }
};
