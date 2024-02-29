#include <cstdint>
#include <iostream>
#include <cmath>

class fraction{
    private:
        int32_t _num;
        uint32_t _denum;
        int NOD(uint32_t a, uint32_t b);
        void sel(int32_t num, uint32_t denom);
        int abc(double copy);

    public:
        fraction();
        fraction(int32_t n_num, uint32_t n_denum);
        fraction(double number);
        inline void print(){
            int answer = fabs(_num/(int)_denum);
            if (answer >= 1){
                sel(_num, _denum);
            }
            else{
                std::cout<<fabs(_num)<<"/"<<_denum<<std::endl;
            }
        }
};