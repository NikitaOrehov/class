//Это файл-хиддер
#pragma once
#include <iostream>
#include <cstdint>
class Fraction{
private:
    int32_t _num; //Поля класса
    uint32_t _denom;
    int NOD(uint32_t a, uint32_t b);
    void sel(int32_t num, uint32_t denom);
    int abc(double copy);

public:
    Fraction(double number);
    Fraction(); //Конструктор по умолчанию
    Fraction(int32_t num, uint32_t denom); //Конструктор с параметрами
    Fraction(const Fraction& fraction);//Копирование класса

    //Геттеры
    void SetNum(int32_t newNum);
    void SetDenom(uint32_t newDenom);

    //Сеттеры
    inline int32_t GetNum(){
        return _num;
    }
    inline uint32_t GetDenom(){
        return _denom;
    }

    bool IsValid = true;

    void Print();//Метод, сигнатура тут, сам код в Fraction.cpp
    inline void PrintDouble(){
        if (_num == 0){
            std::cout <<_num<< std::endl;
            return;
        }
        std::cout << static_cast<double>(_num)/_denom << std::endl;
    }

    //Перегрузка операции вывода в консоль
    friend std::ostream& operator<<(std::ostream& os, const Fraction& tmp){ //принимает ссылку на поток вывода, конст ссылку на наш класс 
        if (tmp._denom == 1){
            os << tmp._num;
            return os;
        }
        os << tmp._num << "/" << tmp._denom;
        return os;
    }

    //перегрузка операции сложения
    Fraction operator+(const Fraction& fraction) const {
        int32_t new_num = _num * fraction._denom + fraction._num * _denom;
        uint32_t new_denum = fraction._denom * _denom;
        return Fraction(new_num, new_denum);
    }

    Fraction operator+(double number) const {
        int res = _num  + number * _denom;
        return Fraction(res, _denom);
    }

    Fraction operator-(const Fraction& fraction) const {
        int32_t new_num = _num * fraction._denom - _denom * fraction._num;
        uint32_t new_denom = _denom * fraction._denom;
        return Fraction(new_num, new_denom);
    }

    Fraction operator*(const Fraction& fract) const {
        int32_t new_num = _num * fract._num;
        uint32_t new_denom = _denom * fract._denom;
        return Fraction(new_num, new_denom);
    }

    Fraction operator*(int number){
        int32_t num = _num * number;
        return Fraction(num, _denom);
    }

    Fraction operator/(const Fraction& fract) const {
        int32_t new_num = _num * fract._denom;
        uint32_t new_denom = _denom * fract._num;
        return Fraction(new_num, new_denom);
    }

    Fraction& operator=(const Fraction& fract){
        _num = fract._num;
        _denom = fract._denom;
        return *this;
    }

    bool operator>(int number) const {
        return _num > number;
    }

    bool operator<(const Fraction& fract) const {
        return (_num * (int32_t)fract._denom < fract._num * (int32_t)_denom);
    }

    bool operator>(const Fraction& fract) const {
        return (_num * (int32_t)fract._denom > fract._num * (int32_t)_denom);
    }

    bool operator>=(const Fraction& fract) const {
        return (_num * (int32_t)fract._denom >= fract._num * (int32_t)_denom);
    }

    bool operator<=(const Fraction& fract) const {
        return ((_num * static_cast<int32_t>(fract._denom)) <= (fract._num * (int32_t)_denom));
    }

    bool operator==(const Fraction& fract) const {
        return (_num * static_cast<int32_t>(fract._denom) == fract._num * static_cast<int32_t>(_denom));
    }

    bool operator!=(const Fraction& fract) const {
        return (_num * static_cast<int32_t>(fract._denom) != fract._num * static_cast<int32_t>(_denom));
    }

    Fraction operator^(int number) const {
        int32_t num = 1;
        int32_t denom = 1;
        for (int i = 0; i < number; i++){
            num *= _num;
            denom *= _denom;
        }
        return Fraction(num, denom);
    }

    Fraction operator-(){
        _num *= -1;
        return Fraction(_num, _denom);
    }

    Fraction operator++(){
        _num += _denom;
        return *this;
    }

    Fraction operator--(){
        _num -= _denom;
        return *this;
    }

    Fraction operator++(int number){
        Fraction copy = Fraction(_num, _denom);
        _num += _denom;
        return copy;
    }

    Fraction operator--(int number){
        Fraction copy = Fraction(_num, _denom);
        _num -= _denom;
        return copy;
    }

    operator double() const {/////////////////////
        return static_cast<double>(_num) / _denom;
    }

    void reduction();

    ~Fraction(){
    }
};