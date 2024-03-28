#include <iostream>

template<typename T>
class Vector{
private:
    T* _array;
    size_t _size;
public:
    Vector() = delete;
    Vector(size_t size, T* array): _size(size), _array(new T[size]){
        for (int i = 0; i < _size; i++){
            _array[i] = array[i];
        }
    }

    Vector(size_t size): _size(size), _array(new T[size]){
        for (int i = 0; i < size; i++){
            _array[i] = 0;
        }
    }

    Vector(std::initializer_list<T> list){
        _size = list.size();
        _array = new T[_size];
        int i = 0;
        for (auto elem = list.begin(); elem != list.end(); elem++, i++){
            _array[i] = *elem;
        }
    }

    const T& operator[](int i) const {
        T* tmp = new T[2];
        _array = tmp;
        _size = 10;
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

    ~Vector(){
        delete [] _array;
    }


    //дз + - * нормализация и получение длины
};