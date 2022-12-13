#include <iostream>
#include <vector>

/* Class template partial specialisation */
template <typename T, int columns>
class PrettyPrinter{
    T * m_pData;
public:
    PrettyPrinter(T * data): m_pData(data){

    }
    void Print(){
        std::cout << "Columns:" << columns << std::endl; 
        std::cout << "{" << *m_pData << "}" << std::endl;
    }

    T * GetData(){
        return m_pData;
    }
};

template<typename T>
class PrettyPrinter<T, 80> {
        T * m_pData;
public:
    PrettyPrinter(T * data): m_pData(data){

    }
    void Print(){
        std::cout << "Using 80 columns:" << std::endl; 
        std::cout << "{" << *m_pData << "}" << std::endl;
    }

    T * GetData(){
        return m_pData;
    }
};

template<typename T>
class SmartPointer{
    T * m_ptr;
public:
    SmartPointer(T * ptr):m_ptr{ptr}{
        std::cout << "SmartPointer(T * ptr)" << std::endl;
    }

    T * operator ->(){
        return m_ptr;
    }

    T & operator *(){
        return *m_ptr;
    }

    ~SmartPointer(){
        std::cout << "~SmartPointer()" << std::endl;
        delete m_ptr;
    }
};

template<typename T>
class SmartPointer<T[]>{
    T * m_ptr;
public:
    SmartPointer(T * ptr):m_ptr{ptr}{
        std::cout << "SmartPointer(T * ptr)" << std::endl;
    }

    T & operator [](int index){
        return m_ptr[index];
    }

    ~SmartPointer(){
        std::cout << "~SmartPointer([])" << std::endl;
        delete[] m_ptr;
    }
};



int main37(){
    
    int data{777};
    PrettyPrinter<int, 50> pp1{&data};
    pp1.Print();

    SmartPointer<int[]> s1{new int[5]};
    s1[0] = 5;
    std::cout << s1[0] << std::endl;
    return 0;
}