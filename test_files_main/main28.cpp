#include <iostream>
#include <string>
#include <filesystem>

/* filesystem example (C++17) */

int main(){
    // std::string filename(R"(./temp/test.txt)");
    // std::cout << filename << std::endl;
    // std::string message(R"MSG(C++ introduced filesystem API "(in C++17)")MSG");
    // std::cout << message << std::endl;

    using namespace std::filesystem;
    path p {R"(./temp/test.txt)"};

    if(p.has_filename()){
        std::cout << p.filename() << std::endl;
    }

    for( const auto &x : p){
        std::cout << x << std::endl;
    }

    directory_iterator beg{p};
    directory_iterator end{};
    while (beg != end){
        std::cout << *beg << std::endl;
        ++beg;
    }


    return 0;
}
