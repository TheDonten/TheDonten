#include <iostream>
#include <sstream>
#include <string>
#include <valarray>
#include <fstream>
#include <cstdio>

using namespace std;

class complex_t {
public:
    complex_t()
    {
        real = 0.0f;
        
        imag = 0.0f;
    }
    complex_t mult(complex_t other)
    {
        complex_t result;
        result.real = this->real * other.real - this->imag * other.imag;
        result.imag = this->imag * other.real - this->real * other.imag;
        return result;
    }
    complex_t div(complex_t other)
    {
        complex_t result;
        result.real = (this->real * other.real + this->real * other.imag) / (other.real * other.real + other.imag * other.imag);
        result.imag = (this->imag * other.real - this->real * other.imag) / (other.real * other.real + other.imag * other.imag);
        return result;
    }
    complex_t sub(complex_t other)
    {
        complex_t result;
        result.real = this->real - other.real;
        result.imag = this->imag - other.imag;
        return result;
    }
    complex_t add(complex_t other) const
    { // complex_t const * const
        // нельзя this = &other;
        complex_t result;
        result.real = this->real + other.real;
        result.imag = this->imag + other.imag;
        return result;
    }
    istream& read(std::istream& stream)
    {
        char op, op1, op2;
        cout << "Введите комлпексное число" << endl;
        if (stream >> op && op == '(' && stream >> real && stream >> op1 && op1 == ',' && stream >> imag && stream >> op2 && op2 == ')') {
            return stream;
        }
        else {
            perror("Wrong");
        }
    }
    ostream& write(std::ostream& stream)
    {
        return stream << '(' << real << ", " << imag << ')';
    }
    ~complex_t()
    {
    }

private:
    float real;
    float imag;
};

int main()
{

    complex_t complex1;
    if (complex1.read(cin)) {
        cout << "Выберите знак действия: '+','-','*','/'; " << endl;
        char op;
        if (cin >> op) {
            complex_t complex2;
            if (complex2.read(cin)) {
                switch (op) {
                case '+': {
                    complex_t result = complex1.add(complex2);
                    result.write(cout);
                    break;
                }
                case '-': {
                    complex_t result = complex1.sub(complex2);
                    result.write(cout);
                    break;
                }
                case '*': {
                    complex_t result = complex1.mult(complex2);
                    result.write(cout);
                    break;
                }
                case '/': {
                    complex_t result = complex1.div(complex2);
                    result.write(cout);
                    break;
                }
                }
            }
        }
    }
    return 0;
}
