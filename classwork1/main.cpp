#include <iostream>
#include "fraction.h"
#include "complex.h"
#include "square.h"

// Fraction operator+(double left, const Fraction& right){
//     Fraction fract = right + Fraction(double);
//     return fract;
// }

int main(){
    Fraction a(1, 1);
    Fraction b(0, 1);
    Fraction c(1, 1);
    square first(a, b, c);
    first.print_root();
    return 0;
}