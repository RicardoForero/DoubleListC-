#include <iostream>
#include <string>
#include "DoubleList.h"

int main() {
    // 1. Instanciar lista de enteros
    DoubleList<int> listaNumeros;
    
    // Agregar datos
    listaNumeros.pushBack(10);
    listaNumeros.pushBack(20);
    listaNumeros.pushFront(5); // La lista queda: 5 <-> 10 <-> 20

    std::cout << "--- LISTA DE ENTEROS ---" << std::endl;
    std::cout << "Hacia adelante: ";
    listaNumeros.displayForward(); 

    std::cout << "Hacia atras:    ";
    listaNumeros.displayBackward();
    std::cout << "Tamano actual: " << listaNumeros.size() << std::endl << std::endl;

    // 2. Instanciar lista de strings
    DoubleList<std::string> listaNombres;
    
    listaNombres.pushBack("Estructuras");
    listaNombres.pushBack("De");
    listaNombres.pushBack("Datos");

    std::cout << "--- LISTA DE STRINGS ---" << std::endl;
    listaNombres.displayForward();

    // 3. Probar eliminacion y volver a imprimir
    std::cout << "\nEliminando el primero y el ultimo..." << std::endl;
    listaNombres.popFront();
    listaNombres.popBack();
    
    std::cout << "Resultado final: ";
    listaNombres.displayForward();

    return 0;
}