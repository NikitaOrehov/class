#include "fraction.h"
#include <cmath>

int NOD(uint32_t number1, uint32_t number2){
    int temp = number1 % number2, answer;
    if (temp == 0) return number2;
    answer = NOD(number2, temp);
    return answer;
}



fraction::fraction(int32_t n_num, uint32_t n_denum){
    if (n_denum == 0) throw "denum can not be zero";
    uint32_t number = fabs(n_num);
    if (number > n_denum) number = NOD(number, n_denum);
    else number = NOD(n_denum, number);
    _num = n_num / (int32_t)number;
    _denum = n_denum / number;
}



fraction::fraction(){
    _num = 1;
    _denum = 2;
}



fraction::fraction(double number){
    int32_t number1 = fabs(number), number2 = 0, lenght = 0, temp, count = 0;
    if (number1 == 0) number1 = 1;
    double copy = number;
    while(1){//находим кол-во цифр после запятой
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

    for (int i = 0; i < lenght; i++){
        number *= 10;
        number2 = number2 * 10 + (int)(number) % 10;
    }
    uint32_t num = number1 * pow(10, lenght) + fabs(number2);
    uint32_t denum = pow(10, lenght);
    //fraction(num, denom);//почему не работает
    int nod = 1;
    if (num > denum) nod = NOD(num, denum);
    else nod = NOD(denum, num);
    if (number > 0) _num = num / nod;
    else _num = (-1 * num) / nod;
    _denum = denum / nod;
} 
