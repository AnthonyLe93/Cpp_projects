#include <iostream>
/* type conversion from basic - basic types */
using namespace std;

int main2(){
    int a = 5;
    int b = 2;
    int c;
    float f = static_cast<float>(a) / b;
    char *p = reinterpret_cast<char*>(&a);
    const int x = 1;
    int *p2 = const_cast<int*>(&x);
    cout << f << endl;

    return 0;
}