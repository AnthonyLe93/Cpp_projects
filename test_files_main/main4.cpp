#include <iostream>
#include "Integer.hpp"

/* type conversion from user-defined - basic types */
std::ostream & operator <<(std::ostream & out, const Integer &a){
    out << a.GetValue();
    return out; 
}
void Print(const Integer &a){
    using namespace std;
    cout << a << endl;
}

int main4() {
    Integer a1{5};
    //Initialisation
    Integer a2 = 5;
    Print(5);
    //Assignment
    a1.SetValue(7);
    //conversion
    int x = static_cast<int>(a1);

    return 0;
}