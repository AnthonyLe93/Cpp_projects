#include <iostream>
#include "Integer.hpp"
/* Direct initialisation using constructor */
class Product{
    Integer m_Id;
    int x;
public:
    Product(const Integer & id):m_Id(id), x(id.GetValue()) {
        std::cout << "Product(const Integer & id)" << std::endl;
    }
    ~Product(){
        std::cout << "~" << std::endl;
    }
};

int main6(){
    using namespace std;
    Product p{5};
    return 0;
}

