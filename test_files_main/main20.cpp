#include <iostream>
#include <string>
#include <initializer_list>
#include <cassert>

/* initializer_list */

class Bag{
    int arr[10];
    int m_Size{};
public:
    Bag(std::initializer_list<int> list){
        assert(list.size() < 10);
        auto it = list.begin();
        while(it != list.end()){           
            Add(*it);
            ++it;
        }
    }
    void Add(int value){
        assert(m_Size < 10);
        arr[m_Size++] = value; //m_Size is set here
    }    
    void Remove(){
        --m_Size;
    }
    int operator[](int index){
        return arr[index];
    }

    int GetSize()const{
        return m_Size;
    }
    int GetValue(int index)const{
        return arr[index];
    }

    void PrintBag(){
        int i = 0;
        std::cout << "Print bag in class: ";
        while(i < m_Size){
            std::cout << arr[i] << " ";
            ++i;
        }
        std::cout << std::endl;
    }
};
std::ostream & operator <<(std::ostream & out, const Bag &b){
    int begin{0};
    int * index;
    index = &begin;
    out << b.GetValue(*index);
    return out; 
}
void Print(std::initializer_list<int> values){
    // auto it = values.begin();
    // while (it != values.end()){
    //     std::cout << *it << " ";
    //     ++it;
    // }
    std::cout << "Print initialiser list: ";
    for(auto x : values){
        
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
int main(){
    int x {45};
    float y{123.56};
    int arr[5]{1,2,3,4,5};
    std::string s{"Hello World"}; 

    std::initializer_list<int> data = {1,2,3,4};
    auto list = {7,8,9,10}; 

    Bag b{6,5,8,4,2};
    // b.Add(3);
    // b.Add(4);
    // b.Add(5);
    // b.Add(6);
    // b.Add(7);
    // b.Add(8);
    // b.Add(9);

    for (int i = 0; i < b.GetSize(); ++i){
        std::cout << "Print bag in main: ";
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    Print({4,5,6,8,7,9});
    b.PrintBag();


    std::cout << "Print bag overload cout ";
    std::cout << b[2] << std::endl;
    std::cout << std::endl;
    return 0;


}