#include <iostream>
#include "vector.h"

int main(){
    int array1[3] = {1, 2, 3};
    int array2[3] = {1, 2, 4};
    Vector vec1 = Vector(3, array1);
    Vector vec2 = Vector(3, array2);
    Vector vec3 = vec1 + vec2;
    Vector vec4 = vec1 - vec2;
    std::cout<<vec1<<std::endl;
    vec1.PrintLenght();
    std::cout<<vec1<<std::endl;
    Vector vec5 = vec1.normal();
    vec5.PrintLenght();
    return 0;
}