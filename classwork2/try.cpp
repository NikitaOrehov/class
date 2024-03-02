#include <iostream>

template<typename T>
auto divide(T a, T b){
    if (b == 0) throw "Error";
    return (double)a / b;
}

int main(){
    int a, b;
    double answer;
    std::cin >> a >> b;
    try{
        answer = divide(a, b);
    }
    catch(const char* message){
        std::cout<<message<<std::endl;
        return -1;
    }
    std::cout<<answer<<std::endl;
}