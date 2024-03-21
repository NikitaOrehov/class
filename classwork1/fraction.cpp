#include "fraction.h"
#include <cmath>

int Fraction::NOD(uint32_t number1, uint32_t number2){
    int temp = number1 % number2, answer;
    if (temp == 0) return number2;
    answer = NOD(number2, temp);
    return answer;
}

void Fraction::reduction(){
    int nod = NOD(fabs(_num), _denom);
    _num = _num / nod;
    _denom = _denom / nod;
}

void Fraction::sel(int32_t num, uint32_t denom){
    int number = num / (int)denom;
    std::cout<<number;
    int new_num = fabs(num) - fabs(number) * denom;
    std::cout<<" "<<new_num<<"/"<<denom<<std::endl;
}

int Fraction::abc(double copy){
    int temp, count= 0, lenght = 1;
    while(1){//РЅР°С…РѕРґРёРј РєРѕР»-РІРѕ С†РёС„СЂ РїРѕСЃР»Рµ Р·Р°РїСЏС‚РѕР№
        temp = (int)(copy * 10) % 10;
        copy *= 10;
        if (temp == 0){
            count++;
            if (count == 5) break;
            continue;
        }
        else{
            lenght += count;
            count = 0;
        }
        lenght++;
        if (lenght == 12) break;
    }
    return lenght;
}

Fraction::Fraction(double number){
    if (number == 0){
        _num = 0;
        _denom = 1;
        return;
    }
    int32_t number1 = fabs(number), number2 = 0, lenght;
    double copy = number;
    lenght = abc(copy);
    for (int i = 0; i < lenght; i++){
        number *= 10;
        number2 = number2 * 10 + (int)(number) % 10;
    }
    int32_t num = fabs(number);
    if (number != 0)  int32_t num = number1 * pow(10, lenght) + fabs(number2);
    uint32_t denum = pow(10, lenght);
    int nod = 1;
    if (num > denum) nod = NOD(num, denum);
    else nod = NOD(denum, num);
    if (number > 0) _num = num / nod;
    else _num = (-1 * (int32_t)num) / nod;
    _denom = denum / nod;
} 

void Fraction::Print(){
    //this -> //Помогает посмотреть какие есть поля класса
    if (_denom == 1){
        std::cout<<_num<<std::endl;
        return;
    }
    std::cout << _num << "/" << _denom << std::endl;
}

void Fraction::SetDenom(uint32_t newDenom){
    if (newDenom == 0)
        throw "Denomirate can't be zero.";
    _denom = newDenom;
}

void Fraction::SetNum(int32_t newNum){
    _num = newNum;
}

Fraction::Fraction(){
    _num = 0;
    _denom = 1;
}

Fraction::Fraction(int32_t num,uint32_t denom){
    _num = num;
    SetDenom(denom);
    reduction();
}

//Копирование класса fract1->fract1_copy
Fraction::Fraction(const Fraction& fraction){
    _num = fraction._num;
    _denom = fraction._denom;
}