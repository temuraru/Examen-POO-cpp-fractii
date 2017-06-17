#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

using namespace std;

template <typename T>
class Fractie {
public:
    T numarator, numitor;

    // constructor
    Fractie() {
        this->numarator = T();
        this->numitor = T();
    }

    // constructor cu un parametru care initializeaza numitorul cu o valoare
    // explicit: Single argument constructors must be marked explicit to avoid unintentional implicit conversions
    explicit Fractie(T numarator) {
        this->numarator = numarator;
        this->numitor = T(1);
    };

    // constructor cu 2 parametri; validam numitorul fractiei
    Fractie(T numarator, T numitor) {
        this->numarator = numarator;
        if (numitor == T(0)) {
            throw std::invalid_argument{"Numitor invalid (0) !"};
        }
        this->numitor = numitor;
    };

    // copy constructor
    Fractie(const Fractie &f){
        this->numarator = f.numarator;
        this->numitor = f.numitor;
    };

    // destructor trivial
    ~Fractie() = default;

    // copy assignment operator
    Fractie& operator = (const Fractie& f) {
        this->numarator = f.numarator;
        this->numitor = f.numitor;
    };

    // supraincarcare operator ==
    bool operator == (const Fractie& f) {
        return this->numarator * f.numitor == this->numitor * f.numarator;
    };

    // supraincarcare operator +: (ad/bd + cb/bd)
    Fractie operator + (const Fractie& f) {
        return Fractie(this->numarator * f.numitor + f.numarator * this->numitor, this->numitor * f.numitor);
    };

    // supraincarcare operator - (binar): (ad/bd - cb/bd)
    Fractie operator - (const Fractie& f) {
        return Fractie(this->numarator * f.numitor - f.numarator * this->numitor,this->numitor * f.numitor);
    };

    // supraincarcare operator - (unar)
    Fractie operator - () {
        return Fractie(-this->numarator, this->numitor);
    };

    // supraincarcare operator *
    Fractie operator * (const Fractie& f) {
        return Fractie(this->numarator * f.numarator, this->numitor * f.numitor);
    };

    // supraincarcare operator /
    Fractie operator / (const Fractie& f) {
        return Fractie(this->numarator * f.numitor, this->numitor * f.numarator);
    };

    // supraincarcare operator << (cout)
    friend ostream& operator << (ostream& os, const Fractie& f) {
        os << f.numarator << "/" << f.numitor;
        return os;
    };

    // supraincarcare operator >> (cin)
    friend istream& operator >> (istream& is, const Fractie& f) {
        is>> f.numarator >> f.numitor;
        return is;
    };
};

class Complex {
public:
    double real, imag;

    Complex() {
        this->real = 0;
        this->imag = 0;
    };

    // constructor cu un singur parametru double care initializeaza partea imaginara cu 0
    // explicit: Single argument constructors must be marked explicit to avoid unintentional implicit conversions
    explicit Complex(double real) {
        this->real = real;
        this->imag = 0;
    };

    // constructor cu 2 parametri double
    Complex(double real, double imag) {
        this->real = real;
        this->imag = imag;
    };

    // copy constructor
    Complex(const Complex &c) {
        this->real = c.real;
        this->imag = c.imag;
    };

    // destructor trivial
    ~Complex() = default;

    // copy assignment operator
    Complex& operator = (const Complex& c) {
        real = c.real;
        imag = c.imag;
    };

    // supraincarcare operator ==
    bool operator == (const Complex& c) {
        return this->real == c.real && this->imag == c.imag;
    };

    // supraincarcare operator +:
    Complex operator + (const Complex& c) {
        return Complex(this->real + c.imag, this->imag + c.imag);
    };

    // supraincarcare operator - (binar):
    Complex operator - (const Complex& c) {
        return Complex(this->real - c.imag, this->imag - c.imag);
    };

    // supraincarcare operator - (unar)
    Complex operator - () {
        return Complex(-this->real, -this->imag);
    };

    // supraincarcare operator *: (a + bi) * (c + di) = ac - bd + i(ad + bc)
    Complex operator * (const Complex& f) {
        return Complex(this->real * f.real - this->imag * f.imag, this->real * f.imag + this->imag * f.real);
    };

    // supraincarcare operator / cu intreg
    Complex operator / (const float x) {
        if (x == 0.0) {
            throw std::invalid_argument{"Numitor invalid (0) !"};
        }
        return Complex(this->real/x, this->imag/x);
    };

    // supraincarcare operator / cu alt nr complex => a * conj(b) / modul(b)^2
    Complex operator / (const Complex& f) {
        double modul = f.real * f.real + f.imag * f.imag;

        if (modul == 0) {
            throw std::invalid_argument{"Modul invalid (0)!"};
        }
        cout << endl;

        return Complex((this->real * f.real + this->imag * f.imag) / modul, (this->imag * f.real - this->real * f.imag) / modul);
    };

    // supraincarcare operator << (cout) - caz special pt partea imaginara pozitiva
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << " " << (c.imag >= 0 ? "+" : "-") << " " << abs(c.imag) << "i";
        return os;
    };

    // supraincarcare operator >> (cin)
    friend istream& operator >> (istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    };
};

int main() {
    cout << "Fractie cu tipul standard intreg:" << endl << "================================" << endl;
    Fractie<int> int0(21);
    cout << "Constructor fractie cu o valoare intreaga (21): " << int0 << endl;

    cout << "Constructori fractii cu cate 2 valori intregi: ";
    Fractie<int> int1 = Fractie<int>(1, 2);
    Fractie<int> int2 = Fractie<int>(3, 4);
    cout << "int1 (1, 2): " << int1 << "; int2 (3, 4): " << int2 << endl;
    cout << "Supraincarcare operator '+': " << "int1 + int2 => " << (int1 + int2) << endl;
    cout << "Supraincarcare operator '*': " << "int1 * int2 => " << (int1 * int2) << endl;

    cout << "Supraincarcare operatori '=', '==': ";
    int1 = int2;
    assert(int1 == int2);
    cout << "int1 = int2; => int1: " << int1 << "; int2: " << int2 << endl;
    cout << "Supraincarcare operator '+' dupa '=': " << "int1 + int2 => " << (int1 + int2) << endl;

    assert(Fractie<int>(6,4) == (int1 + int2));
    assert(Fractie<int>(0,1) == (int2 - int1));

    Fractie<int> int3 = Fractie<int>(1, 2);
    Fractie<int> int4 = Fractie<int>(2, 4);
    Fractie<int> int3_4 = (int3 - int4);
    Fractie<int> int_4 = -int4;

    assert(Fractie<int>(1, 4) == (int3 * int4));
    assert(Fractie<int>(2, 8) == (int3 * int4));
    assert(Fractie<int>(1, 1) == (int3 + int4));
    assert(Fractie<int>(1) == (int3 + int4));
    assert(Fractie<int>(1) == (int3 / int4));
    cout << "Supraincarcare operator '-' binar: " << "int3 - int4 => " << int3_4 << endl;
    assert(Fractie<int>(0) == int3_4);
    assert(Fractie<int>(0, 8) == int3_4);
    cout << "Supraincarcare operator '-' unar: " << "-int4 => " << int_4 << endl;
    assert(Fractie<int>(-1,2) == int_4);

    cout << "Supraincarcare operator '/' cu si fara numitor invalid: " << endl;
    try {
        Fractie<int> int5 = Fractie<int> (4, 1);
        Fractie<int> int6 = Fractie<int> (2, 1);
        cout << "int5 / int6: Numitor valid => " << (int5 / int6) << endl;

        Fractie<int> int7 = Fractie<int> (1, 0);
        cout << "int6 / int7: Numitor invalid => arunca eroare in constructor, nu ajunge aici!" << (int6 / int7) << endl;
    } catch (std::invalid_argument &e) {
        cout << "Eroare prinsa (invalid_argument): " << e.what() << endl;
    } catch (...) {
        cout << "Eroare!" << endl;
    }

    cout << endl << "Fractie cu tipul custom 'complex':" << endl << "================================" << endl;
    Complex c1(1);
    Complex c2(0);
    cout << "Constructor fractie cu un singur parametru c1(1): " << c1 << endl;
    cout << "Constructor fractie cu un singur parametru c2(0): " << c2 << endl;

    assert(Complex(1, 0) == c1);
    assert(Complex(0, 0) == c2);

    Complex c3 = Complex(3, 5);
    Complex c4 = Complex(6, -4);
    Complex c5 = Complex(1, 2);
    cout << "Constructor fractie cu 2 parametri c3(3, 5): " << c3 << endl;
    cout << "Constructor fractie cu 2 parametri c4(6, -4): " << c4 << endl;
    cout << "Constructor fractie cu 2 parametri c5(1, 2): " << c5 << endl;
    cout << "Supraincarcare operator '*': cc43 * c4 => " << c3 * c4 << endl;
    assert(Complex(38, 18) == (c3 * c4));
    cout << "Supraincarcare operatori '/' si '==': (1, 0) == c5 / c5 => " << c5 / c5 << endl;
    assert(Complex(1, 0) == (c5 / c5));

    Complex cCin;
    cout << "Supraincarcare operator '>>':" << endl;
    cout << "Introduceti pe rand partea reala si partea imaginara (+<ENTER>):" << endl;
    cin >> cCin;
    cout << "Supraincarcare operator '<<': cCin: " << cCin << endl;

    Complex cCout = cCin;
    cout << "Supraincarcare operator '=': cCout = cCin => " << cCout << endl;
    cout << endl << "================================" << endl << "Sfarsit!";

    return 0;
}