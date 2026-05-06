#include <iostream>
#include "./cifrador/main.hpp"

using namespace std;

int cifrar() {
    cout << "Cifrando" << endl;
}

int main() {
    Cipher Cesar("Cesar", cifrar);
    return 0;
}