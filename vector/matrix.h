#pragma once
#include "vector.h"
#include <random>

template <typename T>

class matrix{
private:
    Vector<T>* _vectors;
    size_t _size;
public:
    matrix() = delete;
    matrix(size_t rows, size_t cols, int i = 0){
        _size = rows;
        _vectors = new Vector<T>[rows];
        for (size_t i = 0; i < _size; i++){
            _vectors[i] = Vector<T>(cols);
        }
        if (i != 0){
            std::mt19937 gen;
            gen.seed(std::random_device()());
            std::uniform_int_distribution<std::mt19937::result_type>dist;
            for (int i = 0; i < _size; i++){
                for (int j = 0; j < cols; j++){
                    _vectors[i][j] = static_cast<int>(-1000 + dist(gen) % 2001);
                }
            }
        }
    }

    matrix(size_t rows){
        _size = rows;
        _vectors = new Vector<T>[rows];
        for (size_t i = 0; i < _size; i++){
            _vectors[i] = Vector<T>(rows);
        }
    }

    matrix(const matrix& matr){
        int cols = matr._vectors[0].GetSize();
        _size = matr._size;
        _vectors = new Vector<T>[_size];
        for (int i = 0; i < _size; i++){
            _vectors[i] = Vector<T>(cols);
        }
        for (int i = 0; i < _size; i++){
            for (int j = 0; j < cols; j++){
                _vectors[i][j] = matr._vectors[i][j];
            }
        }

    }

    size_t GetSize(){
        return _size;
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

    void print_matrix(){
        for (int i = 0; i < _size; i++){
            for (int j = 0; j < _vectors[0].GetSize(); j++){
                std::cout<<_vectors[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }

    matrix operator/(T number){
        for (int i = 0; i < _size; i++){
            for (int j = 0; j < _vectors[0].GetSize(); j++){
                _vectors[i][j] = _vectors[i][j] / number;
            }
        }
        return *this;
    }

    matrix<T>& operator=(const matrix matr){
        size_t cols = _vectors[0].GetSize();
        if (_size != matr._size || _vectors[0].GetSize() != cols){
            throw 1;
        }
        _size = matr._size;
        for (int i = 0; i < _size; i++){
            for (int j = 0; j < cols; j++){
                _vectors[i][j] = matr[i][j];
            }
        }
        return *this;
    }

    matrix<T> operator+(const matrix matr) const {
        size_t cols = _vectors[0].GetSize();
        if (_size !=  matr._size || cols != matr._vectors[0].GetSize()){
            std::cout<<"error"<<std::endl;
            throw 1;
        }
        matrix matr1 = matrix(matr._size, cols);
        for (int i = 0; i < _size; i++){
            for (int j = 0; j < cols; j++){
                matr1[i][j] = _vectors[i][j] + matr._vectors[i][j];
            }
        }
        return matr1;
    }

    matrix<T> operator-(const matrix matr) const {
        size_t cols = _vectors[0].GetSize();
        if (_size !=  matr._size || cols != matr._vectors[0].GetSize()){
            std::cout<<"error"<<std::endl;
            throw 1;
        }
        matrix matr1 = matrix(matr._size, cols);
        for (int i = 0; i < _size; i++){
            for (int j = 0; j < cols; j++){
                matr1[i][j] = _vectors[i][j] - matr._vectors[i][j];
            }
        }
        return matr1;
    }

    matrix<T> operator*(const matrix matr) const {
        size_t cols = _vectors[0].GetSize();
        if (cols != matr._size){
            std::cout<<"error"<<std::endl;
            throw 1;
        }
        matrix matr1 = matrix(matr._size, cols);
        for (int i = 0; i < _size; i++){
            for (int j = 0; j < cols; j++){
                for (int l = 0; l < cols; l++){
                    matr1[i][j] += _vectors[i][l] * matr._vectors[l][j];
                }
            }
        }
        return matr1;
    }

    matrix<T> operator/(matrix<double> matr) const {
        matrix answer = *this * matr.reverse_matrix();
        return answer;
    }

    void transposition(){
        size_t cols = _vectors[0].GetSize();
        if (_size != cols){
            throw 1;
        }
        for (int i = 0; i < _size; i++){
            for (int j = i + 1; j < cols; j++){
                T temp = _vectors[i][j];
                _vectors[i][j] = _vectors[j][i];
                _vectors[j][i] = temp;
            }
        }
    }

    matrix<double> reverse_matrix(){
        if (this->determinant() == 0){
            std::cout<<"matrix viragdena"<<std::endl;
            throw 1;
        }
        matrix<double> new_matrix = matrix<double>(_size);
        for (int i = 0 ; i < _size; i++){
            for (int j = 0; j < _size; j++){
                matrix dop_matrix = matrix(_size - 1);
                int rows = 0;
                for (int k = 0; k < _size; k++){
                    if (k == j){
                        continue;
                    }
                    int cols = 0;
                    for (int l = 0; l < _size; l++){
                        if (l == i){
                            continue;
                        }
                        dop_matrix[rows][cols] = _vectors[k][l];
                        cols += 1;
                    }
                    rows += 1;
                }
                new_matrix[i][j] = pow(-1, j + i) * dop_matrix.determinant();
            }
        }
        new_matrix = new_matrix / this->determinant();
        return new_matrix;
    }

   T determinant(){
        size_t cols = _vectors[0].GetSize();
        if (_size != cols){
            throw 1;
        }
        if (_size == 2){
            return _vectors[0][0] * _vectors[1][1] - _vectors[0][1] * _vectors[1][0];
        }
        T det = 0;
        matrix matr1 = *this;
        for (int i = 0; i < _size; i++){
            if (_size == 3){
                det +=  pow(-1, i) * matr1[0][i] * help_deter(matr1, i);
            }
            else{
                det +=  pow(-1, i) * help_deter(matr1, i);
            }
        }
        return det;
    }

    T help_deter(matrix matr, int k){
        size_t size = matr._size - 1;
        matrix new_matr = matrix(size);
        for (int i = 1; i < matr._size; i++){
            int cols = 0;
            for (int j = 0; j < matr._size; j++){
                if (j == k){
                    continue;
                }
                new_matr[i - 1][cols] = matr[i][j];
                cols += 1;
            }
        }
        T det = 0;
        if (size == 2){
            return new_matr[0][0] * new_matr[1][1] - new_matr[0][1] * new_matr[1][0];
        }
        else{
            for (int i = 0; i < size; i++){
                det += pow(-1, i) * matr[0][k] * help_deter(new_matr, i);
            }
        }
        return det;
    }

    ~matrix(){
        delete [] _vectors;
    }


};//перегрузить сложение, разность, умножение, деление. Нахождение обратной матрицы, определитель, транспонирование, рандомное заполнение элементов. Реализовать векторное определение векторов 