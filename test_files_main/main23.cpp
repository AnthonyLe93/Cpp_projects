#include <iostream>

/* Inheritance and Composition */
class Animal{
public:
    void Eat(){
        std::cout << "Animal eating" << std::endl;
    }
    void Run(){
        std::cout << "Animal running" << std::endl;
    }
    void Speak(){
        std::cout << "Animal speaking" << std::endl;
    }
};

class Dog: public Animal{
public:
    void Eat(){
        std::cout << "Dog eating meat" << std::endl;
    }
    void Run(){
        std::cout << "Animal running" << std::endl;
    }
    void Speak(){
        std::cout << "Dog barking" << std::endl;
    }
};

int main(){
    Dog dog;
    dog.Eat();
    dog.Run();
    dog.Speak();

    return 0;
}