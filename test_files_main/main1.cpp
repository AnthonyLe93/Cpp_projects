# include <iostream>
# include <vector>
# include "Integer.hpp"
# include <memory>
/* Class construction and operators overloading */

Integer operator +(const Integer &a, const Integer &b){
    Integer temp;
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}

std::ostream & operator <<(std::ostream & out, const Integer &a){
    out << a.GetValue();
    return out; 
}

std::istream & operator >>(std::istream &input, Integer &a){
    int x;
    input >> x;
    *a.m_pInt = x;
    return input;
}

void CreateInteger(){
    Integer *p = new Integer;
    p->SetValue(3);
    std::cout << p->GetValue() << std::endl;
    delete p;
}


class IntPtr{
    Integer *m_p;
public:
    IntPtr(Integer *p):m_p(p){

    }
    ~IntPtr() {
        delete m_p;
    }
    Integer *operator ->(){
        return m_p;
    }

    Integer & operator *(){
        return *m_p;
    }
};

void Process(std::shared_ptr<Integer> ptr){
    std::cout << ptr->GetValue() << std::endl;
}
int main1(){
    std::shared_ptr<Integer> p(new Integer);
    (*p).SetValue(3);

    Process(p);
    return 0;

}