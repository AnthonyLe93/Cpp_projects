#include <iostream>
#include "union.hpp"

/* Union */


int main(){
    // Test t;
    // std::cout << sizeof(t) << std::endl;
    // std::cout << t.ch << std::endl;
    // t.x = 1000;
    //std::cout << t.ch << std::endl; //undefined behaviour when access non
    //active function.
    using namespace std::string_literals;
    UDT udt; 
    //new(&udt.s) std::string {"Hello World"};
    new(&udt.a) A{};
    udt.a.~A();
    return 0;
}