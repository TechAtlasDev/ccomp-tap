#include <iostream>
#include <functional>
#include "./main.hpp"

using namespace std;

Cipher::Cipher(const char* nombre, function algo) {
    _nombre = nombre;
    cout << _nombre << " inicializado de manera exitosa" << endl;
};
