#include <iostream>
#include <memory>
#include <vector>


/* Exception Handling*/

class Test{
public:
    Test(){
        std::cout << "Test()" <<std::endl;
    }

    ~Test(){
        std::cout << "~Test()" <<std::endl;
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

    return 0;
}

int main(){
    try{
        // ProcessRecord(std::numeric_limits<int>::max());
        ProcessRecord(5);
    } 
    // catch (std::runtime_error &ex){
    //     std::cout << ex.what() << std::endl;
    // }
    // catch (std::out_of_range &ex){
    //     std::cout << ex.what() << std::endl;
    // }
    // catch (std::bad_alloc &ex){
    //     std::cout << ex.what() << std::endl;
    // }
    catch (std::exception &ex){
        std::cout << ex.what() << std::endl;
    }
    catch (...){
        std::cout << "Exception" << std::endl; // avoid using as it provides no useful info
    }

    return 0;
}

