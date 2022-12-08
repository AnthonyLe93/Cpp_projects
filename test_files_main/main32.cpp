#include <iostream>
#include <string>
/* Template */

// int Max(int x, int y){
//     return x > y? x :y;
// }

// float Max(float x, float y){
//     return x > y? x :y;
// }

template<typename T> 
T Max(T x, T y){
    std::cout << typeid(T).name() << std::endl;
    return x>y? x:y; 
}

// Explicit instantiation
template char Max(char x, char y);

// Explicit specialisation
template<> const char * Max(const char *x, const char *y){
    std::cout << "Max(const char *x, const char *y)" << std::endl;
    return strcmp(x, y) > 0? x:y;
}

// Non-type template argument
template<int size>
void Print(){
    char buffer[size];
    std::cout << size << std::endl;
}


// template<typename T>
// T Sum(T *parr, int size){
//     T sum {};
//     for(int i = 0; i < size; ++i){
//         sum += parr[i];
//     }
//     return sum;
// }

template<typename T, int size>
T Sum(T (&parr)[size]){
    T sum {};
    for(int i = 0; i < size; ++i){
        sum += parr[i];
    }
    return sum;
}

int main(){
    //Instantiation examples
    // auto num = Max(static_cast<float> (3), 9.23f);
    // std::cout << num << std::endl;
    // auto char_ = Max<char>(3, 'B');
    // std::cout << char_ << std::endl;
    // int(*pfunc)(int,int) = Max; //pointer to template function with type int
    
    // std::string s1{"hello, my name is anthony le"};
    // std::string s2{"HELLO, MY NAME IS ANTHONY LE"};
    // auto s3 = Max(s1, s2);
    // std::cout << s3 << std::endl;
    
    // const char * b{"B"};
    // const char * a{"A"};
    // auto s = Max(a, b);
    // std::cout << s << std::endl;

    // Print<3>();
    int arr[]{1,2,3,4,5};
    auto it = std::begin(arr);
    //int (&ref)[5] = arr;
    //int sum = Sum(arr, sizeof(arr)/sizeof(arr[0]));
    int sum = Sum(arr);
    std::cout << sum << std::endl;

    return 0;
}