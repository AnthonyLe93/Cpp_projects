#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

/* Using fstream for both input and output */
void Write(){
    std::ofstream out("./temp/test.txt");
    if(!out){
        std::cout << "Could not open file for writing" << std::endl;
        return;
    }
    std::cout << "Current write position is: " << out.tellp() << std::endl;
    std::string message{"C++ was invented by Bjarne.\n"
                        "This is an example text file"
                        "create for learning modern C++."};

    // for(char ch: message){
    //     out.put(ch);
    // }
    out << message;

    // out.seekp(5);
    // out << "££££££££££££";
    out.close();

}

void Read() {

    std::ifstream input("./temp/test.txt");
    if(!input){
        std::cout << "source file not found" << std::endl;
        return;
    }
    std::cout << "Current read position is: " << input.tellg() << std::endl;
    // input.seekg(10, std::ios::beg);
    // std::cout << "Current read position is: " << input.tellg() << std::endl;
    // char ch{};
    std::string line;
    // while(input.get(ch)){
    //     std::cout << ch;
    // }
    while(std::getline (input,line)){
        std::cout << line << std::endl;
    }


    input.close();
}

void UsingFstream(){
    std::fstream stream("./temp/test2.txt");
    if(!stream){
        std::ofstream out{"./temp/test2.txt"};
        out.close();
        stream.open("./temp/test2.txt");
    }
    std::string message {"This is the second test file.\n"
                         "This text file is used to test the"
                         " fstream (input and output).\n"
                         "This line is the end of the file."};
    stream << message << std::endl;
    
    stream.seekg(0); //reset file pointer to 0 position
    std::string line;
    while(std::getline(stream, line)){
        std::cout << line << std::endl;
    }
    stream.close();
    
}

int main(){
    // using namespace std::filesystem;
    // path source(current_path());
    // source /= "main.cpp";

    // path dest(current_path());
    // dest /= "temp/copy_main.cpp";
    // std::fstream input{source};
    // if(!input){
    //     std::cout << "Source file not found" << std::endl;
    //     return -1;
    // }

    // std::ofstream output{dest};
    // std::string line;

    // while(!std::getline(input, line).eof()){
    //     output << line << std::endl;
    // }
    // input.close();
    // output.close();


    Write();
    Read();
    UsingFstream();
    return 0;
}