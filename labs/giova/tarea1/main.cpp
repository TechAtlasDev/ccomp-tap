#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

template <class C>
struct Less {

    bool operator()(C a, C b) {
        return a < b;
    }
};

template <class C>
struct Greater {

    bool operator()(C a, C b) {
        return a > b;
    }
};

template <class C, class Comparator>
void merge(C* ar,
           int left,
           int mid,
           int right,
           Comparator cmp) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    C* L = new C[n1];
    C* R = new C[n2];

    for(int i = 0; i < n1; i++)
        L[i] = ar[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = ar[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2) {

        // TEMPLATE
        if(cmp(L[i], R[j])) {
            ar[k++] = L[i++];
        }
        else {
            ar[k++] = R[j++];
        }
    }

    while(i < n1)
        ar[k++] = L[i++];

    while(j < n2)
        ar[k++] = R[j++];

    delete[] L;
    delete[] R;
}

template <class C, class Comparator>
void mergeSort(C* ar,
               int left,
               int right,
               Comparator cmp) {

    if(left < right) {

        int mid = (left + right) / 2;

        mergeSort(ar, left, mid, cmp);
        mergeSort(ar, mid + 1, right, cmp);

        merge(ar, left, mid, right, cmp);
    }
}

template <class C>
void print(C* ar, int n) {

    for(int i = 0; i < n; i++)
        cout << ar[i] << " ";

    cout << endl;
}

int main() {

    const int N = 50000;

    int* ar = new int[N];

    for(int i = 0; i < N; i++)
        ar[i] = rand();

    Less<int> cmp;

    auto inicio = chrono::high_resolution_clock::now();

    mergeSort(ar, 0, N - 1, cmp);

    auto fin = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tiempo = fin - inicio;

    cout << "Tiempo templates: "
         << tiempo.count()
         << " ms" << endl;

    delete[] ar;

    return 0;
}
