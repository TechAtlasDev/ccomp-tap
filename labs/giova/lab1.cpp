#include <iostream>
#include <assert.h>

class XVector
{
public:
    XVector();
    XVector(unsigned long s);
    XVector(const XVector& r);
    ~XVector();
    int get(unsigned long i);
    int& operator[](unsigned long i);
    const XVector& operator=(const XVector& v);

    XVector operator+(const XVector& v);
    XVector operator-(const XVector& v);
    XVector operator*(const XVector& v);
    XVector operator/(const XVector& v);

    XVector operator+(const int v);
    XVector operator-(const int v);
    XVector operator*(const int v);
    XVector operator/(const int v);

    void print();
    friend std::ostream& operator<<(std::ostream& os, const XVector& v);
    friend std::istream& operator<<(std::istream& os, const XVector& v);
private:
    int* vec;
    unsigned long size;
};

XVector::XVector(const XVector& r)
{
    std::cout<<" -constructor copia- ";
    size = r.size;
    vec = new int[size];
    for ( int i = 0; i < size; ++i )
        vec[i] = r.vec[i];
}

XVector::XVector()
{
    std::cout<<" -constructor vacio- ";
    size = 0;
    vec = 0;
}

XVector::XVector(unsigned long s )
{
    std::cout<<" -constructor- ";
    size = s;
    vec = new int[size];
}

XVector::~XVector()
{
    std::cout<<" -destructor- ";
    delete[] vec;
}

int& XVector::operator[](unsigned long i)
{
    assert(i < size);
    return vec[i];
}

const XVector& XVector::operator=( const XVector& v)
{
    size = v.size;
    if ( vec )   delete [] vec;
    vec = new int [size];
    for ( int i = 0; i < size; ++i )
        vec[i] = v.vec[i];
    return v;
}

XVector XVector::operator+( const XVector& v)
{
    assert(size == v.size);
    XVector r(v.size);
    for ( unsigned long i = 0; i < size; ++i )
        r.vec[i] = v.vec[i] + vec[i];
    return r;
}

XVector XVector::operator+( const int v)
{
    XVector r(size);
    for ( unsigned long i = 0; i < size; ++i )
        r.vec[i] = vec[i] + v;
    return r;
}

XVector XVector::operator-( const XVector& V) {
    assert(size == V.size);
    XVector r(V.size);
    for ( unsigned long i = 0; i < size; ++i )
        r.vec[i] = vec[i] - V.vec[i];
    return r;
}

XVector XVector::operator-( const int V) {
    XVector r(size);
    for ( unsigned long i=0; i<size; ++i) {
        r.vec[i] = vec[i] - V;
    }
    return r;
}

XVector XVector::operator*( const XVector& V) {
    assert(size == V.size);
    XVector r(V.size);
    for ( unsigned long i = 0; i < size; ++i )
        r.vec[i] = vec[i] * V.vec[i];
    return r;
}

XVector XVector::operator*( const int V) {
    XVector r(size);
    for (unsigned int i=0; i<size; ++i) {
        r.vec[i] = vec[i] * V;
    };
    return r;
}

XVector XVector::operator/( const int V) {
    XVector r(size);
    for (unsigned int i=0; i<size; ++i) {
        r.vec[i] = vec[i] / V;
    };
    return r;
}

XVector XVector::operator/(const XVector V) {
    assert size == V.size;
    XVector r(size);
    for (unsigned int i=0; i<size; ++i) {
        r[i] = vec[i] / V.vec[i];
    }
    return r;
}

void XVector::print()
{
    for (unsigned long i = 0; i < size; i++)
        std::cout << vec[i] << " ";
    std::cout << "\n";
}

std::ostream& operator<<(std::ostream& os, const XVector& v)
{
    for (unsigned long i = 0; i < v.size; i++)
        std::cout << v.vec[i] << " ";
    std::cout << "\n";
    return os;
}

std::istream& operator<<(std::istream& os, const XVector& v)
{
    for (unsigned long i = 0; i < v.size; i++)
        std::cin >> v.vec[i];
    return os;
}


int main()
{
    XVector va(5);
    XVector vb(va), vc, vd, ve, vf;
    
    va[0] = 10; va[1] = 20;
    va[2] = 30; va[3] = 40; va[4] = 50;
    va.print();
    
    vc = vb = va;
    vb.print();
    vc.print();
    
    vc = vb + va;
    vc.print();
    
    std::cout<<vc<<" -- "<<va;

    vd = vc - 2;
    std::cout <<"AAAA" << std::endl;
    vd.print();

    std::cout << "Multiplicando escalar" << std::endl;
    ve = vd * 2;

    ve.print();

    vf = ve / 2;
    vf.print();
    
    return 0;
}

