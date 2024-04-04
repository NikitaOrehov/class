#pragma once
#include "vector.h"

template <typename T>

class matrix{
private:
    Vector<T>* _vectors;
    size_t _size;
public:
    matrix() = delete;
    matrix(size_t rows, size_t cols){
        _size = rows;
        _vectors = new Vector<T>[rows];
        for (size_t i = 0; i < _size; i++){
            _vectors[i] = Vector<T>(cols);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const matrix& matr){
        for (int i = 0; i < matr._size; i++){
            os << matr._vectors[i] << std::endl;
        }
        return os;
    }

    const Vector<T>& operator[](int index) const{
        return _vectors[index];
    }

    Vector<T>& operator[](int index){
        return _vectors[index];
    }
};//перегрузить сложение, разность, умножение, деление. Нахождение обратной матрицы, определитель, транспонирование, рандомное заполнение элементов. Реализовать векторное определение векторов 