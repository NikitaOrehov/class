#include <iostream>
#include <cmath>

template<typename T>
class Vector{
private:
    T* _array;
    size_t _size;
    double _lenght;

public:
    Vector();
    Vector(size_t size, T* array): _size(size), _array(new T[size]){
        for (int i = 0; i < _size; i++){
            _array[i] = array[i];
        }
        _lenght = find_lenght();
    }
    Vector(size_t size): _size(size), _array(new T[size]){
        for (int i = 0; i < size; i++){
            _array[i] = 0;
        }
        _lenght = find_lenght();
    }
    Vector(std::initializer_list<T> list){
        _size = list.size();
        _array = new T[_size];
        int i = 0;
        for (auto elem = list.begin(); elem != list.end(); elem++, i++){
            _array[i] = *elem;
        }
        _lenght = find_lenght();
    }

    Vector<double> normal(){
        double* new_array = new double[_size];
        for (int i = 0; i < _size; i++){
            new_array[i] = _array[i] / _lenght;
        }
        return Vector<double>(_size, new_array);
    }

    double find_lenght(){
        double number = 0;
        for (int i = 0; i < _size; i++){
            number += _array[i] * _array[i];
        }
        return sqrt(number);
    }

    const T& operator[](int i) const {
        return _array[i];
    }


    friend std::ostream& operator<<(std::ostream& os,  const Vector& vec){
        for (int i = 0; i < vec._size; i++){
            os << vec._array[i];
            if (i + 1 !=  vec._size)
                os << ", ";
        }
        return os;
    }

    Vector operator+(const Vector& vec) const {
        if (_size != vec._size){
            std::cout<<"error +"<<std::endl;
            exit(1);
        }
        T* new_array = new T[_size];
        for (int i = 0; i < _size; i++){
            new_array[i] = _array[i] + vec._array[i];
        }
        return Vector(_size, new_array);
    }

    Vector operator-(const Vector& vec) const {
        if (_size != vec._size){
            std::cout<<"error -"<<std::endl;
            exit(1);
        }
        T* new_array = new T[_size];
        for (int i = 0; i < _size; i++){
            new_array[i] = _array[i] - vec._array[i];
        }
        return Vector(_size, new_array);
    }

    auto operator*(const Vector& vec) const {
        if (_size != vec._size){
            std::cout<<"error *"<<std::endl;
            exit(1);
        }
        auto number = 0;
        for (int i = 0; i < _size; i++){
            number += _array[i] * vec._array[i];
        }
        return Vector(3);
    }

    // Vector& operator=(const Vector& vec){
    //     _lenght = vec._lenght;
        
    // }

    void PrintLenght(){
        std::cout<<_lenght<<std::endl;
    }

    ~Vector(){
        delete [] _array;
    }


    //дз + - * нормализация и получение длины
};