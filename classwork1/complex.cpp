#include "complex.h"


Complex::Complex(){
    _re = Fraction();
    _im = Fraction();
}

Complex::Complex(Fraction re, Fraction im){
    _re = re;
    _im = im;
}

Complex::Complex(int num_re, int denom_re, int num_im, int denom_im){
    _re = Fraction(num_re, denom_re);
    _im = Fraction(num_im, denom_im);
}

Complex Complex::operator+(const Complex& number) const {
    Fraction re = _re + number._re;
    return Complex(re, _im);
}

Complex Complex::operator=(const Complex& number){
    _re = number._re;
    _im = number._im;
    return Complex(_re, _im);
}

