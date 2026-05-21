#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

template <class C>
struct LessEstatico {
    inline bool operator()(const C& a, const C& b) const { return a < b; }
};

template <class C, class Comparator>
void mergeEstatico(C* ar, C* temp, int left, int mid, int right, Comparator cmp) {
    int i = left, j = mid + 1, k = left;
    for (int idx = left; idx <= right; idx++) temp[idx] = ar[idx];
    while (i <= mid && j <= right) {
        if (cmp(temp[i], temp[j])) ar[k++] = temp[i++];
        else ar[k++] = temp[j++];
    }
    while (i <= mid) ar[k++] = temp[i++];
}

template <class C, class Comparator>
void mergeSortEstaticoInternal(C* ar, C* temp, int left, int right, Comparator cmp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortEstaticoInternal(ar, temp, left, mid, cmp);
        mergeSortEstaticoInternal(ar, temp, mid + 1, right, cmp);
        mergeEstatico(ar, temp, left, mid, right, cmp);
    }
}

template <class C, class Comparator>
void mergeSortEstatico(C* ar, int n, Comparator cmp) {
    C* temp = new C[n];
    mergeSortEstaticoInternal(ar, temp, 0, n - 1, cmp);
    delete[] temp;
}

template <class C>
struct ComparatorDinamico {
    virtual bool compare(const C& a, const C& b) const = 0;
    virtual ~ComparatorDinamico() {}
};

template <class C>
struct LessDinamico : public ComparatorDinamico<C> {
    bool compare(const C& a, const C& b) const override { return a < b; }
};

template <class C>
void mergeDinamico(C* ar, C* temp, int left, int mid, int right, const ComparatorDinamico<C>& cmp) {
    int i = left, j = mid + 1, k = left;
    for (int idx = left; idx <= right; idx++) temp[idx] = ar[idx];
    while (i <= mid && j <= right) {
        if (cmp.compare(temp[i], temp[j])) ar[k++] = temp[i++];
        else ar[k++] = temp[j++];
    }
    while (i <= mid) ar[k++] = temp[i++];
}

template <class C>
void mergeSortDinamicoInternal(C* ar, C* temp, int left, int right, const ComparatorDinamico<C>& cmp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortDinamicoInternal(ar, temp, left, mid, cmp);
        mergeSortDinamicoInternal(ar, temp, mid + 1, right, cmp);
        mergeDinamico(ar, temp, left, mid, right, cmp);
    }
}

template <class C>
void mergeSortDinamico(C* ar, int n, const ComparatorDinamico<C>& cmp) {
    C* temp = new C[n];
    mergeSortDinamicoInternal(ar, temp, 0, n - 1, cmp);
    delete[] temp;
}

int main() {
    int cantidad_filas = 100000000;

    cout << "Estatico,Dinamico\n";

    for (int idx = 1; idx <= cantidad_filas; idx++) {
        int N = idx * 25000;
        int* ar1 = new int[N];
        int* ar2 = new int[N];

        for (int i = 0; i < N; i++) {
            int num = rand();
            ar1[i] = num;
            ar2[i] = num;
        }

        LessEstatico<int> cmpEstatico;
        auto inicio = chrono::high_resolution_clock::now();
        mergeSortEstatico(ar1, N, cmpEstatico);
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tEstatico = fin - inicio;

        LessDinamico<int> cmpDinamico;
        inicio = chrono::high_resolution_clock::now();
        mergeSortDinamico(ar2, N, cmpDinamico);
        fin = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tDinamico = fin - inicio;

        cout << tEstatico.count() << "," << tDinamico.count() << "\n";

        delete[] ar1;
        delete[] ar2;
    }

    return 0;
}
