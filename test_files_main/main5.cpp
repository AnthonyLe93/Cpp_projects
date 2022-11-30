#include <iostream>
#include "Integer.hpp"

/* type conversion from user-defined - user-defined types */

class Product{
    Integer m_Id;
public:
    Product(const Integer & id):m_Id{id}{
        std::cout << "Product(const Integer &)" << std::endl;
    }
    ~Product(){
        std::cout << "~" << std::endl;
    }
    const Integer & GetInteger()const{
        return m_Id;
    }

    operator Integer(){
        return m_Id;
    }
};

int main5(){
    Product p{5};
    Integer id{5};
    //id = p; // id = p.operator Integer();

    if(id == p){
        std::cout << "Id matches with the product" << std::endl;
    }

    return 0;
}

