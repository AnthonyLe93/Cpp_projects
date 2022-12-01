# include <iostream>


/* Constexpr */
constexpr int GetNumber(){
    return 42;
}

constexpr int Add (int x, int y){
    return x + y;
}

// constexpr int Max(int x, int y){
//     return x > y ? x : y; // Only contain one line return statement
// }
constexpr int Max(int x, int y){
    if (x > y)
        return x;
    return y; //allow in C++14    
}

int main19() {
    //Behave as a constexpr function (evaluate at complie time)
    constexpr int i = GetNumber();
    int arr[i];

    //Behave as a constexpr function
    const int j = GetNumber();
    int arr1[j];

    //Behave as a normal function (evaluate at run time)
    int x = GetNumber();

    //Evaluate at compile time (very fast)
    constexpr int sum = Add(56, 12);
    std::cout << "sum = " << sum << std::endl;

    ////Evaluate at run time (slower)
    int sum2 = Add(7,7);
    std::cout << "sum2 = " << sum << std::endl;

    constexpr int max = Max(42, i);
    return 0;
}

/*Constant expression function rules

1. Should accept and return literal types only
   void, scalar types(int, float, char, etc...)
2. Should contain only single line statement that should be a return statement.
   C++14 allows multi lines in function
3. constexpr functions are implicitly inline   

*/