#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;

class XVector {
private:
    int _len;
    int* data;

public:
    XVector(int len);
    ~XVector();
    void imprimir();
    void generate();
    void set(int pos, int value);

    float sort_index();         
    float sort_pointer_math();
    float sort_mixed();
};

XVector::XVector(int len) : _len(len) {
    data = new int[len];
    for (int i = 0; i < len; i++) data[i] = 0;
}

XVector::~XVector() {
    delete[] data;
}

float XVector::sort_index() {
    auto inicio = chrono::high_resolution_clock::now();
    for (int i = 0; i < _len - 1; i++) {
        for (int j = 0; j < _len - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<float, std::milli> tiempo = fin - inicio;
    return tiempo.count();
}

float XVector::sort_pointer_math() {
    auto inicio = chrono::high_resolution_clock::now();
    for (int i = 0; i < _len - 1; i++) {
        for (int* p = data; p < data + _len - i - 1; p++) {
            if (*p > *(p + 1)) {
                int temp = *p;
                *p = *(p + 1);
                *(p + 1) = temp;
            }
        }
    }
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<float, std::milli> tiempo = fin - inicio;
    return tiempo.count();
}

float XVector::sort_mixed() {
    auto inicio = chrono::high_resolution_clock::now();
    for (int i = 0; i < _len - 1; i++) {
        for (int j = 0; j < _len - i - 1; j++) {
            if (*(data + j) > *(data + j + 1)) {
                int temp = *(data + j);
                *(data + j) = *(data + j + 1);
                *(data + j + 1) = temp;
            }
        }
    }
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<float, std::milli> tiempo = fin - inicio;
    return tiempo.count();
}

void XVector::generate() {
    for (int i = 0; i < _len; i++) data[i] = rand() % 100;
}

void XVector::imprimir() {
    cout << "[ ";
    for (int i = 0; i < _len; i++) cout << data[i] << " ";
    cout << "]" << endl;
}

int main() {
    XVector v(10);

    for (int i=0; i<100; i++) {
        
    }

    return 0;
}
