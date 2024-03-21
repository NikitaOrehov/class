#include "square.h"
#include <cmath>

square::square(Fraction a, Fraction b, Fraction c){
    _a = a;
    _b = b;
    _c = c;
    _discriminant = (_b * _b) - (_a * _c * 4);
    root();
}//почему не могу вызвать конструктор для root1?

void square::root(){
    if (_discriminant.GetNum() == 0){
        Complex root(Fraction(-_b, _a * 2), Fraction(0));
        _root1 = root;
        _root2 = root;
    }
    else if(_discriminant.GetNum() > 0){
        Fraction z = static_cast<Fraction>(sqrt(_discriminant));
        Fraction first = (-_b - z) /  (_a * 2);  
        Complex x(first, Fraction(0));
        _root1 = x;
        Fraction second = (-_b + static_cast<Fraction>(sqrt(_discriminant))) /  (_a * 2);
        Complex y(second, Fraction(0));
        _root2 = y;
    }
    else{
        Fraction first = _b / (_a * 2);
        Fraction second = static_cast<Fraction>(sqrt(-_discriminant)) / (_a * 2);
        Complex x(first, second);
        Complex y(first, -second);
        _root1 = x;
        _root2 = y;
    }

}

void square::print(){
        std::cout<<_root1<<std::endl;
        std::cout<<_root2<<std::endl;
}
