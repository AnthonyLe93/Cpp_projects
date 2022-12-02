#include <iostream>
#include "union.hpp"


Test::Test() : ch{'a'}{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
Test::~Test(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

A::A(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
}
A::~A(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
}
A::A(const A & other){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
}
A::A(A && other)noexcept{
        std::cout << __PRETTY_FUNCTION__ << std::endl;
}

A & A::operator=(const A & other){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(this == &other){
        return *this;
    }
    return *this;
}
A & A::operator=(A && other)noexcept{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(this == &other){
        return *this;
    }
    return *this;
}

B::B(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
}
B::~B(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
}
B::B(const B & other){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
}
B::B(B && other)noexcept{
        std::cout << __PRETTY_FUNCTION__ << std::endl;
}

B & B::operator=(const B & other){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(this == &other){
        return *this;
    }
    return *this;
}
B & B::operator=(B && other)noexcept{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(this == &other){
        return *this;
    }
    return *this;
}

