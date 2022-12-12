# include <iostream>
# include <string>
# include <vector>

/* Class template explicit specialisation */
template<typename T>
class PrettyPrinter{
    T *m_pData;
public:
    PrettyPrinter(T * data):m_pData(data){

    }
    void Print(){
        std::cout << "{" << *m_pData << "}" << std::endl;
    }
    T * GetData(){
        return m_pData;
    }

};
template<>
void PrettyPrinter<std::vector<int>>::Print(){
        std::cout << "{";
        for(const auto &x : *m_pData){
            std::cout << x;
        }
        std::cout << "}" << std::endl;
}

// template<>
// class PrettyPrinter<std::vector<int>>{
//     std::vector<int> *m_pData;
// public:
//     PrettyPrinter(std::vector<int> * data):m_pData(data){

//     }
//     void Print(){
//         std::cout << "{";
//         for(const auto &x : *m_pData){
//             std::cout << x;
//         }
//         std::cout << "}" << std::endl;
//     }
//     std::vector<int> * GetData(){
//         return m_pData;
//     }

// };


int main36(){
    // int data = 5;
    // float f = 8.2f;
    // PrettyPrinter<int> pp1{&data};
    // PrettyPrinter<float> pp2{&f};
    // pp1.Print();
    // pp2.Print();

    // std::string s{"Hello World!"};
    // PrettyPrinter<std::string> pp3{&s};
    // pp3.Print();

    std::vector<int> v{1,2,3,4,5,6};
    PrettyPrinter<std::vector<int>> pp4{&v};
    pp4.Print();


    return 0;
}