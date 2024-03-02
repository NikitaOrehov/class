#include <iostream>
#include "fraction.h"

int main(){
    // Fraction fract1;
    // fract1.SetNum(1);
    // fract1.SetDenom(2);
    // fract1.PrintDouble();
    
    // Fraction fract2();
    // Fraction fract3 = Fraction();
    
    Fraction fract = Fraction(3,2);

    // std::cout << fract;


    Fraction fract_copy = Fraction(fract);
    // std::cout << fract_copy;
 
    // // Fraction* fract_pointer = new Fraction();
    // // delete fract_pointer;

    // Fraction result = fract + fract_copy;
    // Fraction result1 = fract - fract_copy;
    // Fraction result2 = fract * fract_copy;
    // Fraction result3 = fract / fract_copy;
    // //Fraction result = fract.operator+(fract_copy);
    // std::cout<<result;
    // std::cout<<result1;
    // std::cout<<result2;
    // std::cout<<result3;

    // Fraction *pointerFract = new Fraction();
    // delete pointerFract;

    Fraction* massivFraction = new Fraction[5]{
        {1,2},
        {1,3},
        {1,4},
        {1,6},
        fract
    };
    // for (int i = 0; i < 5; i++){
    //     massivFraction[i] = Fraction(1, i + 1);
    // }

    // delete [] massivFraction;

    //дз > < <= >= != ^ ~ ++ --
    //
}