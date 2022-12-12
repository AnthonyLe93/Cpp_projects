#pragma once
#include<iostream>

class Integer{
    int * m_pInt;
public:
    Integer();
    //Parameterised constructor
    Integer(int value);

    //Copy constructor
    Integer(const Integer &obj);

    //Move constructor
    Integer(Integer && obj);

    //Copy assignment
    Integer & operator=(const Integer &obj);

    //Move assignment
    Integer & operator=(Integer && obj);

    int GetValue()const;
    void SetValue(int value);
    ~Integer();

    //Operator overloading
    // Integer operator +(const Integer & a) const;
    Integer & operator ++();
    Integer operator ++(int);
    bool operator == (const Integer obj) const;
    void operator ()();
    friend std::istream & operator >> (std::istream & input, Integer &a);
    friend class Printer;
    explicit operator int();
    
};

class Printer{

};

std::ostream & operator <<(std::ostream & out, const Integer &a);