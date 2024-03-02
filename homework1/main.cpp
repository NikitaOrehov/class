#include "fraction.h"

using namespace std;

int main(){
    int a, b;
    cin>> a >> b;
    try{
        fraction object(a, b);
        object.print();
    }
    catch(const char* message){
        cout<<message<<endl;
    }
    // fraction object2(); почему не работает
    // object2.print();
    fraction object2(-1.65);
    object2.print();
}