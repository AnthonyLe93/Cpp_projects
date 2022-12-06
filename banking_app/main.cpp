#include <iostream>
#include <memory>
#include <vector>
#include <random>

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
    try{
        // ProcessRecord(std::numeric_limits<int>::max());
        ProcessRecord(10, 1);
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

