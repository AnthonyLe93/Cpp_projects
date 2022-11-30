#include <iostream>
#include "Integer.hpp"
#include <memory>
/* raw pointer */
void Display(Integer *p){
    if(!p){
        return;
    }
    std::cout << p->GetValue() << std::endl;
}

Integer * GetPointer(int value){
    Integer *p = new Integer(value);
    return p;
}


void Store(std::unique_ptr<Integer> &p){
    std::cout << "Stroeing data into a file" << p->GetValue() << std::endl;
}

void Operate(int value){
    std::unique_ptr<Integer>p(GetPointer(value));
    if(p == nullptr){
        //p = new Integer(value);
        p.reset(new Integer(value));
    }
    p -> SetValue(value);
    Display(p.get());
    //delete p;
    p = nullptr;
    p.reset(new Integer(value));
    *p = __LINE__;
    Display(p.get());
    Store(p);
    *p = 200;
    //delete p;
}


int main7(){
    Operate(5);

    return 0;
}