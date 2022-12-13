# include <iostream>
/* Lambda expressions */
template<typename T>
struct unnamed{
    T operator()(T x, T y)const{
        return x + y;
    }
};
int main42(){
    auto fn = [](){
        std::cout << "Welcome to Lambda expressions" << std::endl;
    };
    fn();
    // std::cout << typeid(fn).name() << std::endl;
    auto sum = [](auto x, auto y)noexcept{
        return x + y;
    };
    std::cout << "Sum is: " << sum(5,6) << std::endl;
    std::cout << "Sum is: " << sum(5.0f,6.6f) << std::endl;

    unnamed<int> n;
    std::cout << "Sum2 is: " << n(5,6) << std::endl;
    return 0;
}