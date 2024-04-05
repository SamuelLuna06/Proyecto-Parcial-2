#include "./BatallaNaval.hpp"

BatallaNaval::BatallaNaval()
{
}

BatallaNaval::~BatallaNaval()
{
}

void BatallaNaval::iniciarTablero()
{
    for (int i = 0; i < TAMANO_TABLERO; ++i)
    {
        vector<char> fila;
        for (int j = 0; j < TAMANO_TABLERO; ++j)
        {
            fila.push_back('~');
        }
        this->tablero.push_back(fila);
    }
}

void BatallaNaval::mostrarTablero()
{
    cout << "  ";
    for (int i = 0; i < TAMANO_TABLERO; ++i)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < TAMANO_TABLERO; ++i)
    {
        cout << i << " ";
        for (int j = 0; j < TAMANO_TABLERO; ++j)
        {
            cout << this->tablero[i][j] << " ";
        }
        cout << endl;
    }
}

void BatallaNaval::colocarBarcos()
{
    srand(time(0));
    for (int i = 0; i < NUMERO_BARCOS; ++i)
    {
        Barco barco(rand() % TAMANO_TABLERO, rand() % TAMANO_TABLERO);
        this->barcos.push_back(barco);
    }
}

bool BatallaNaval::acertarBarco(Barco barco)
{
    for (const auto &barcoTablero : this->barcos)
    {
        if (barcoTablero.fila == barco.fila && barcoTablero.columna == barco.columna)
        {
            return true;
        }
    }
    return false;
}

void BatallaNaval::run()
{

    iniciarTablero();
    colocarBarcos();

    int intentos = 0;
    int aciertos = 0;

    cout << "¡Bienvenido a Batalla Naval!" << endl;
    cout << "¡A hundir " << NUMERO_BARCOS << " barcos!" << endl;

    while (aciertos < NUMERO_BARCOS)
    {
        cout << "Intento #" << intentos + 1 << endl;
        mostrarTablero();

        int fila, columna;
        cout << "Introduce la fila y columnaumna para disparar (separadas por un espacio): ";
        cin >> fila >> columna;

        if (fila < 0 || fila >= TAMANO_TABLERO || columna < 0 || columna >= TAMANO_TABLERO)
        {
            cout << "Disparo fuera del tablero. Inténtalo de nuevo." << endl;
            continue;
        }

        if (this->tablero[fila][columna] == 'X' || this->tablero[fila][columna] == 'O')
        {
            cout << "Ya has disparado en esa posición. Inténtalo de nuevo." << endl;
            continue;
        }

        if (acertarBarco(Barco(fila, columna)))
        {
            cout << "¡Has acertado un barco!" << endl;
            this->tablero[fila][columna] = 'X'; // 'X' representa un acierto
            aciertos++;
        }
        else
        {
            cout << "Agua..." << endl;
            this->tablero[fila][columna] = 'O'; // 'O' representa agua
        }
        intentos++;
    }

    cout << "¡Felicidades! ¡Has hundido todos los barcos en " << intentos << " intentos!" << endl;
}