#include <iostream>

int ProcessRecord(int count){
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

