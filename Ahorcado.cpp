#include <iostream>
#include <list>

using namespace std;

class Ahorcado {

    private:
    int opcion;
    int intentos;
    int intentosMaximos;
    string palabra;
    list <string> frutas = {"Cereza", "Manzana", "Pera", "Uva", "Platano", "Fresa", "Mango", "Melon", "Sandia", "Kiwi"};
    list <string> profesiones = {"Abogado", "Arquitecto", "Astronauta", "Bombero", "Carpintero", "Cirujano", "Cocinero", "Dentista", "Electricista", "Ingeniero"};
    list <string> paises = {"Colombia", "Argentina", "Brasil", "Chile", "Ecuador", "Peru", "Venezuela", "Uruguay", "Paraguay", "Bolivia"};
    list <string> deportes = {"Futbol", "Baloncesto", "Voleibol", "Tenis", "Natacion", "Atletismo", "Ciclismo", "Gimnasia", "Boxeo", "Karate"};
    list <string> colores = {"Rojo", "Azul", "Verde", "Amarillo", "Naranja", "Morado", "Blanco", "Negro", "Gris", "Rosado"};
    list <string> mezcla = {"Cereza", "Abogado", "Colombia","Futbol", "Rojo", "Manzana", "Arquitecto", "Argentina", "Baloncesto", "Azul", "Pera", "Astronauta", "Brasil", "Voleibol", "Verde"};

    public:

    void tipoCategoria(){
        cout << "Bienvendio al juego del ahorcado. Elige la categoria que deseas jugar:\n1. Frutas.\n2. Profesiones.\n3. Paises.\n4. Deportes.\n5. Colores.\n6. Mezcla !" << endl;
        cin >> opcion;
        
        
        if(opcion == 1){
            for(const auto & Tipo: frutas){
                cout << Tipo << " " ;
            }
            cout << endl;
        }else if(opcion == 2){
            for(const auto & Tipo: profesiones){
                cout << Tipo << " " ;
            }
            cout << endl;
        }else if(opcion == 3){
            for(const auto & Tipo: paises){
                cout << Tipo << " " ;
            }
            cout << endl;
        }else if(opcion == 4){
            for(const auto & Tipo: deportes){
                cout << Tipo << " " ;
            }
            cout << endl;
        }else if(opcion == 5){
            for(const auto & Tipo: colores){
                cout << Tipo << " " ;
            }
            cout << endl;
        }else if(opcion == 6){
            for(const auto & Tipo: mezcla){
                cout << Tipo << " " ;
            }
            cout << endl;
        }else{
            cout << "Opcion no valida." << endl;
        }
    }
};
