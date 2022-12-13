#include <iostream>
#include <type_traits>

/* Type traits */

template<typename T>
T Divide(T a, T b){
    if(std::is_floating_point<T>::value == false){
        std::cout << "Use floating point types only" << std::endl;
        return 0;
    }
    return a / b;
}

template<typename T>
void Check(T &&){
    std::cout << std::boolalpha;
    std::cout 
    << "Is reference? " 
    << std::is_reference<T>::value 
    << std::endl;

    std::cout 
    << "After removing: " 
    << std::is_reference<typename std::remove_reference<T>::type>::value
    << std::endl;
}

int main39(){
    // std::cout
    // << std::boolalpha
    // << "Is integer? "
    // << std::is_integral<int>::value 
    // << std::endl;

    // std::cout << Divide(5,2) << std::endl;
    Check(5);
    int a {5};
    Check(a);

    return 0;
}



