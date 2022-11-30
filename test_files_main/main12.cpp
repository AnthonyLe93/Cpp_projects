#include <cstdlib>
#include <iostream>

/* Dynamic array with smart pointers */
struct Free{
    void operator()(int * p){
        free(p);
        std::cout << "Pointer freed \n";
    }
};

void MallocFree(int * p){
    free(p);
    std::cout << "Pointer freed \n";
}

void UniquePtrDeleter(){
    std::unique_ptr<int, Free> p ((int*) malloc(4));
    //std::unique_ptr<int, void(*)(int *)> p ((int*) malloc(4), MallocFree);
    *p = 100;
    std::cout << *p << "\n";
}

void SharedPtrDeleter(){
    std::shared_ptr<int> p ((int*) malloc(4));
    //std::shared_ptr<int> p ((int*) malloc(4), MallocFree);
    *p = 100;
    std::cout << *p << "\n";
}

int main12() {
    std::shared_ptr<int[]> p{new int[5]{1,2,3,4,5}};
    p[0] = 10;

}