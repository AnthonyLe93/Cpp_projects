#include <iostream>
#include "Integer.hpp"

/* type conversion from basic - user-defined types */
std::ostream & operator <<(std::ostream & out, const Integer &a){
    out << a.GetValue();
    return out; 
}
void Print(const Integer &a){
    using namespace std;
    cout << a << endl;
}

int main3() {
    Integer a1{5};
    Integer a2 = 5;
    Print(5);
    a1 = 7;
    return 0;
}