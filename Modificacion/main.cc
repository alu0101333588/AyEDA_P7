#include <iostream>
#include "ABE.h"
#include "ABB.h"
#include "dummy.h"

//using Key = int;

using Key = Dummy;

unsigned Dummy::Contador_;

int main() {
    int opcion = -1;
    AB<Key>* arbol;
    

    while (opcion != 1 && opcion != 2) {
        std::cout << "1 -> ABE (Árbol Binario Equilibrado)" << std::endl;
        std::cout << "2 -> ABB (Árbol Binario de Búsqueda)" << std::endl;
        std::cout << "¿Qué tipo de árbol desea?: ";
        std::cin >> opcion;
        std::cout << std::endl;

    }

    

    switch (opcion) {
    case 1:
        arbol = new ABE<Key>;
        break;

    case 2:
        arbol = new ABB<Key>;
        break;
    
    default:
        std::cerr << "ERROR en la opción del árbol" << std::endl;
        break;
    }

    std::cout << "Árbol vacío" << std::endl;
    //arbol->AB<Key>::Imprimir();
    std::cout << arbol << std::endl;

    Key Clave;


    while (opcion != 0) {
        std::cout << "-------------------------" << std::endl;
        std::cout << "[0] Salir" << std::endl;
        std::cout << "[1] Insertar clave" << std::endl;
        std::cout << "[2] Buscar clave" << std::endl;
        std::cout << "[3] Eliminar clave" << std::endl;
        std::cout << "[4] Mostrar árbol inorden" << std::endl;
        std::cout << "[6] Modificación Clase" << std::endl;
        std::cout << "-------------------------" << std::endl;

        std::cin >> opcion;

        switch (opcion){
        case 1:
            std::cout << "Clave (Insertar): ";
            std::cin >> Clave;
            std::cout << "Insertar: " << Clave << std::endl << std::endl;
            if (arbol->insertar(Clave)) {
                std::cout << arbol << std::endl;
                //arbol->Imprimir();
            } else {
                std::cout << "ELEMENTO REPETIDO" << std::endl;
            }
            break;

        case 2: 
            std::cout << "Clave (Busqueda): ";
            std::cin >> Clave;
            std::cout << "Busqueda [" << Clave << "]: ";
            if (arbol->buscar(Clave)) {
                std::cout << "MATCH" << std::endl;
            } else {
                std::cout << "NO EXISTE" << std::endl;
            }
            break;

        case 3:
            std::cout << "Clave (Eliminar): ";
            std::cin >> Clave;
            if (arbol->eliminar(Clave)) {
                std::cout << "Eliminada con éxito la clave: " << Clave << std::endl;
            } else {
                std::cout << "El elemento no existe: " << Clave << std::endl;
            }
            break;
            
        case 4:
            arbol->inorden();
            break;
        
        case 5:
            std::cout << arbol << std::endl;
            break;

        case 6: // Modificación clase
            AB<Key>* arbol1;
            AB<Key>* arbol2;
            arbol1 = new ABB<Key>;
            arbol2 = new ABE<Key>;
            std::cout << "Elementos: " << std::endl;
            for (int i = 0; i < 100; i++) {
                Dummy h = rand() % 100;
                arbol1->insertar(h);
                arbol2->insertar(h);
                
                std::cout << "[" << h << "] ";
            }
            std::cout << std::endl << "ABB:" << std::endl;
            Dummy::Contador_ = 0;
            for (int i = 0; i < 10; i++) {
                Dummy h = rand() % 100;
                //Dummy::Contador_ = 0;
                //Dummy dummy1();
                //dummy1->Contador_ = 0;
                Dummy::Contador_ = 0;
                if (arbol1->buscar(h)) {
                    std::cout << "Elemento: " << h << ". Contador: " << Dummy::Contador_ << std::endl;
                }
                Dummy::Contador_ = 0;
                if (arbol2->buscar(h)) {
                    std::cout << "Elemento: " << h << ". Contador: " << Dummy::Contador_ << std::endl;
                }
            }

            /*std::cout << "ABE:" << std::endl;
            Dummy::Contador_ = 0;
            for (int i = 0; i < 10; i++) {
                Dummy h = rand() % 100;
                //Dummy::Contador_ = 0;
                //Dummy dummy1();
                //dummy1->Contador_ = 0;
                if (arbol2->buscar(h)) {
                    Dummy::Contador_++;
                    std::cout << "Elemento: " << h << ". Contador: " << Dummy::Contador_ << std::endl;
                }
            }*/
        default:
            break;
        }
    }

    return 0;
    

}
