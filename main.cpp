#include <iostream>
#include <fstream>
#include <string>

/* I/O for file stream */

void Write(){
    std::ofstream out{"./temp/test.txt"};
    out << "Hello world" << std::endl;
    out << 101 << std::endl;
    out.close();
}

void Read() {
    // std::ifstream input{"./temp/test.txt"};
    std::ifstream input;
    input.open("./temp/test.txt");
    if(input.fail()){
        std::cout <<"Could not open the file" << std::endl;
        return;
    }
    std::string message;
    std::getline(input, message);
    int value{};
    input >> value;
    input >> value;
    if(input.eof()){
        std::cout << "End of file encountered" << std::endl;
    }
    if(input.good()){
        std::cout << "I/O operations are successful" <<std::endl;
    }
    else{
        std::cout << "Some I/O operations failed" << std::endl;
    }
    input.setstate(std::ios::failbit);
    input.clear();
    input.close();
    std::cout << message << ": " << value << std::endl;
}

int main(){
    Write();
    Read();
    return 0;
}
