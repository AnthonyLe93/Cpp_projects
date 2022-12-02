#include <iostream>
#include <string>

struct A{
    A();
    ~A();
    A(const A & other);
    A(A && other)noexcept;
    A & operator=(const A & other);
    A & operator=(A & other);
    A & operator=(A && other)noexcept;

};
struct B{
    B();
    ~B();
    B(const B & other);
    B(B && other)noexcept;
    B & operator=(const B & other);
    B & operator=(B && other)noexcept;

};

union Test{
    int x;
    char ch;
    double d;
    Test();
    ~Test();
};

union UDT{
    A a;
    B b;
    std::string s;
    UDT(){

    }
    ~UDT(){

    }

};