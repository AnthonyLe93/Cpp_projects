#include <iostream>


/* Noexcept function usage */
void Test(int x){
    throw x;
}

int Sum(const int &x, const int &y)noexcept(noexcept(Test(x))){
    Test(x);
    return x + y;
}

int main(){
    try{
        Sum(3,5);
    }
    catch (int x){
        std::cout << x << std::endl;
    }

    return 0;
}
