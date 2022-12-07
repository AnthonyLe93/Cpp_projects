#include <iostream>
#include <memory>
#include <vector>
#include <random>
#include <string>

/* Exception handling*/
class A{
public:
    A(){
        std::cout << "A()" << std::endl;
    }

    ~A(){
        std::cout << "~A()" << std::endl;
    }
};

class B{
public:
    B(){
        std::cout << "B()" << std::endl;
    }

    ~B(){
        std::cout << "~B()" << std::endl;
    }
};

class Test{
    std::unique_ptr<A> pA{};
    B b{};
    std::shared_ptr<B> pInt{};
    std::shared_ptr<std::string> pStr{};
    std::vector<int> pArr{};
public:
    Test(){
        std::cout << "Test()" <<std::endl;
        pA.reset(new A);
        throw std::runtime_error("Failed to initialised");

        // pA = new A;      
        // pInt = new int;
        // pStr = new char[1000];
        // pArr = new int[50000];
    }

    ~Test(){
        std::cout << "~Test()" <<std::endl;
        // delete pA;
        // delete pInt;
        // delete[] pStr;
        // delete[] pArr;
    }
};

int ProcessRecord(int count){

    std::unique_ptr<Test> t(new Test);

    if (count <10){
        throw std::out_of_range("Count should be greater than 10");
    }
    int * p = new int[count];
    int * pArray = (int*)malloc(count * sizeof(int));
    if(pArray == nullptr){
        throw std::runtime_error("Failed to allocate memory");
    }
    for(int i = 0; i < count; ++i){
        pArray[i] = i;
    }

    free(pArray);
    delete[] p;
    return 0;
}

int ProcessRecord(int count, int id){
    std::unique_ptr<Test> t(new Test);

    if (count <10){
        throw std::out_of_range("Count should be greater than 10");
    }
    std::vector<int> p;
    p.reserve(count);
    std::vector<int> pArray;
    pArray.reserve(count);
    //Process the record
    for(int i = 0; i < count; ++i){
        pArray.push_back(i);
    }
    std::default_random_engine eng;
    std::bernoulli_distribution dist;
    int errors {0};

    for (int i=0; i<count; ++i){
        try{
            std::cout << "Processing record # : " << i << " ";
            if(!dist(eng)){
                ++errors;
                throw std::runtime_error ("Could not process the record");                
            }
            std::cout << std::endl;
        }
        catch(std::runtime_error &ex){
            std::cout << "[ERROR " << ex.what() << "]" << std::endl;
            //std::cout << errors << std::endl;
            if(errors > 4){
                std::runtime_error err("Too many errors. Abandoning operation");
                ex = err;
                throw;
            }
        }
    }
    std::cout << std::endl;

    return 0;
}

int main(){
    // try{
    //     // ProcessRecord(std::numeric_limits<int>::max());
    //     ProcessRecord(10, 1);
    // } 
    // catch (std::runtime_error &ex){
    //     std::cout << ex.what() << std::endl;
    // }
    // catch (std::out_of_range &ex){
    //     std::cout << ex.what() << std::endl;
    // }
    // catch (std::bad_alloc &ex){
    //     std::cout << ex.what() << std::endl;
    // }
    // catch (std::exception &ex){
    //     std::cout << ex.what() << std::endl;
    // }
    // catch (...){
    //     std::cout << "Exception" << std::endl; // avoid using as it provides no useful info
    // }
    try{
        Test t;
    }
    catch(std::runtime_error &ex){
        std::cout << ex.what() << std::endl;
    }
    

    return 0;
}

