#include <iostream>

/* Smart pointers (shared_pointer and weak_pointer) */
class Printer{
    std::weak_ptr<int> m_pValue;
public:
    void SetValue(std::weak_ptr<int> value){
        m_pValue = value;
    }
    void Print(){
        
        if(m_pValue.expired()){
            std::cout << "Resource is no longer available" << std::endl;
            return;
        }
        auto sp = m_pValue.lock();
        std::cout << "value is: " << *sp << std::endl;
        std::cout << "Ref count: " << sp.use_count() << std::endl;
    }
};


int main9(){
    Printer prt;
    int num;

    std::cin >> num;
    std::shared_ptr<int> p{new int(num)};
    prt.SetValue(p);

    if(*p > 10){
        p = nullptr;
    }

    prt.Print();

    return 0;
}