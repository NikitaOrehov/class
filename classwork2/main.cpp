#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

struct yyyyyyyyyyy{
    int a = 0;
};

inline double sqrtt(double a){
    return a * a;
}

double sum(double a, double b = 10){
    return a + b;
}

enum BluetoothState{Con, Dis};

double Divide(double a, double b){
    return a / b;
}

int Divide(int a, int b){
    int res = a / b;
    return res;
}
template<typename T>
double DivideTemplate(T a, T b){
    if (b == 0)
        throw "Delenie na nol";
    return a/b;
}

void change_reference_value(int& a){
    a = 10000;
}

int main(){
    int a = 10; double b = 100;
    double rez = DivideTemplate(10, 1);
    try{
        DivideTemplate(1, 0);
    }catch(const char* message){
        cout<<message<<endl;
    }
    auto myStruct = yyyyyyyyyyy();
    int a = myStruct.a;
    std::cin >> a;
    std::cout << a << std::endl;
    bool isFlaf = false;
    BluetoothState now = BluetoothState::Con;
    switch(now){
        case BluetoothState::Con:
            std::cout <<"fdgjg"<<std::endl;
            break;
        case BluetoothState::Dis:
            std::cout <<"gegnedjk"<<std::endl;
            break;
        default:
            break;
    }
    int* arr = new int[100];
    for (int i = 0; i < 100; i++){
        arr[i] = i;
    }
    delete [] arr;
    cout<<"dfkjghdkgh"<<endl;
    int b = 10;
    int c = 10;
    // const int* const pointer_b = &b;
    // *pointer_b = 100; //нельзя менять значение
    // pointer_b = &c; //нельзя менять адрес
    double base_val = 100;
    int target_val = static_cast<int>(base_val);//смена типа
    //example divide
    double res_div = Divide(10.0, 10.0);
    //int res = Divide()

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8};
    // for (auto elem: a){//механизм обхода массива
    //     cout<<elem<<endl;
    // }
    
    int abc = 10;
    int& ref_abc = abc;
    cout<<ref_abc;
    change_reference_value(abc);

    int** matrix = new int*[5];
    for (int i = 0; i < 5; i++){
        matrix[i] = new int[5];
    }

    for (int i = 0; i < 5; i++){
        delete [] matrix[i];
    }
    delete [] matrix;

    std::mt19937 gen;
    gen.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type>dist;
    std::cout <<dist(gen)<<std::endl;

    


    return 0;
}