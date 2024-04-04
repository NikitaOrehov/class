#include <iostream>
#include "matrix.h"

int main(){
    int array1[3] = {1, 2, 3};
    int array2[3] = {1, 2, 4};
    Vector vec1 = Vector(3, array1);
    Vector vec2 = Vector(3, array2);
    Vector vec3 = vec1 + vec2;
    std::cout<<vec1<<std::endl;
    double* normal;
    normal = vec1.GetNormalVector();
    for (int i = 0; i < 3; i++){
        std::cout<<normal[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<vec1.find_lenght()<<std::endl;
    return 0;
}