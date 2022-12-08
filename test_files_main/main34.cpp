#include <iostream>
#include "Integer.hpp"
/* Variadic template */

// template<typename T>
// void Print(std::initializer_list<T> args){
//     for(const auto &x : args){
//         std::cout << x << " ";
//     }
//     std::cout << std::endl;
// }

//template parameter pack

void Print(){
    // base case function
    std::cout << std::endl;
}

template<typename T, typename ...Params>
void Print(T &&a, Params&&... args){
    // std::cout << sizeof...(args) << std::endl;
    // std::cout << sizeof...(Params) << std::endl;
    std::cout << a;
    if(sizeof...(args) != 0){
        std::cout << ", ";
    }
    Print(std::forward<Params>(args)...);
}

int main34() {
    Integer val{8};
    Print(52, 2.3f, "Anthony Le", true, val);
    return 0;
}

/*
1. Print(52, 2.3f, "Anthony Le", true);
2. Print(2.3f, "Anthony Le", true);
3. Print("Anthony Le", true);
4. Print(true);
5. Print();
*/