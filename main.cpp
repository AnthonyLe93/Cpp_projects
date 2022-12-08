#include <iostream>
#include "Integer.hpp"
#include <string>


class Employee{
    std::string em_name;
    Integer em_id;
public:
    // Employee(const std::string &name, const Integer &id): em_name(name), em_id(id){
    //     std::cout << "Employee(const std::string &name, const Integer &id)" << std::endl;
    // }
    template<typename T1, typename T2>
    Employee(T1 &&name, T2 &&id) : 
    em_name(std::forward<T1>(name)), 
    em_id(std::forward<T2>(id)){
        std::cout << "Employee(T1 &&name, T2 &&id)" << std::endl;
    }

    std::string GetName(){
        return em_name;
    }

    Integer GetId(){
        return em_id;
    }

    ~Employee(){
        std::cout << "~Employee()" << std::endl;
    };
};

template<typename T1, typename T2>
Employee *Create(T1 && a, T2 && b){
    return new Employee(std::forward<T1> (a), std::forward<T2> (b));
}

int main(){

    Integer id{6};
    Employee em1{"Sarah Connor", id};

    auto em2 = Create("Anthony Le", Integer(7));
    return 0;
}
