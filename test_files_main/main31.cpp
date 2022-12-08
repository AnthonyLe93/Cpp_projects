#include <iostream>
#include <fstream>
#include <string>

/* Binary input/output files */
struct Record {
    int id;
    char name[10];
};

void WriteRecord (Record *r){
    std::ofstream binstream{"records", std::ios::binary | std::ios::out};
    binstream.write((const char *)r, sizeof(Record));
}

Record GetRecord(){
    std::ifstream input{"records",  std::ios::binary | std::ios::in};
    Record r;
    input.read((char *)&r, sizeof(Record));
    return r;
}

int main() {

    // std::ofstream textstream{"./temp/data"};
    // textstream << 123456789 << std::endl;
    // std::ofstream binstream{"./temp/binary", std::ios::binary | std::ios::out};
    // int num {12356789};
    // binstream.write((const char *) &num, sizeof(num));
    // num = 0;
    // binstream.close();
    // std::ifstream input{"./temp/binary.bin", std::ios::binary | std::ios::in};
    // input.read((char *)&num, sizeof(num));
    // std::cout << num << std::endl; 


    Record r{1001, "Anthony"};
    WriteRecord(&r);
    Record r2 = GetRecord();
    std::cout <<r2.id << ": " << r2.name << std::endl;
    return 0;
}