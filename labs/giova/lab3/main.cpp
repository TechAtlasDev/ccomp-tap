#include <iostream>

using namespace std;

int procesarMatrizLineal(int* inicio, int tamano) {
    cout << "Recorriendo matriz" << endl;
    return *inicio;
}

int main() {
    int* arreglo = new int[4];
    arreglo[0] = 1;
    int valor = procesarMatrizLineal(arreglo, 4);
    cout << valor << endl;

    return 0;
}