#include <iostream>
#include "fraction.h"
#include "complex.h"
#include "square.h"

// Fraction operator+(double left, const Fraction& right){
//     Fraction fract = right + Fraction(double);
//     return fract;
// }

int main(){
    Fraction a(12, 1);
    Fraction b(6, 1);
    Fraction c(-3, 1);
    square first(a, b, c);
    first.print();
    return 0;
}