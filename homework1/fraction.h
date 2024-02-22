#include <cstdint>
#include <iostream>

class fraction{
    private:
        int32_t _num;
        uint32_t _denum;
    public:
        fraction();
        fraction(int32_t n_num, uint32_t n_denum);
        fraction(double number);
        inline void print(){
            std::cout<<_num<<"/"<<_denum<<std::endl;
        }

};