#include <iostream>
#include "fraction.h"
#include "complex.h"

// Fraction operator+(double left, const Fraction& right){
//     Fraction fract = right + Fraction(double);
//     return fract;
// }

int main(){
    Fraction fract1(1, 3);
    Fraction fract2(-1, 2);
    // double converted = static_cast<double>(fract1);
    // double converted2 = fract1;
    // std::cout<<converted;
    // if (fract1 != fract2) std::cout<<"true";
    // else std::cout<<"false";
    // Fraction res = fract1 ^ 2;
    // std::cout<<res<<std::endl;
    // ++fract1;
    // Complex chislo(fract1, fract2);
    // std::cout<<chislo;
    // Fraction copy = (++fract1);
    // std::cout<<copy<<std::endl;
    // std::cout<<fract1++;
    //дз класс квадратное уравнение. 
    std::cout<<-fract1<<std::endl;
    return 0;
}