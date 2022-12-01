# include <iostream>
# include <cstring>
# include <string>

/* std string class */

const char * Combine(const char * pFirst, const char * pLast){
    char * fullname = new char[strlen(pFirst) + strlen(pLast) + 1];
    strcpy(fullname, pFirst);
    strcat(fullname, pLast);
    return fullname;
}

void UsingStdString(){
     //Initialised & Assign
    std::string s = "Hello";
    s = "Hello again";

    //Access
    s[0] = 'w';
    char c = s[2];
    std::cout << s << std::endl;
    std::cin >> s; //cin will stop reading when encounter 1st space
    std::getline(std::cin, s); // read the entire line with spaces

    //Size
    s.length();

    //Insert & concatenate
    std::string s1{"Hello"};
    std::string s2{"World"};
    std::string s3 = s1 + s2;
    std::cout << s3 << std::endl;
    s3 += s3; 

    s3.insert(6, "Goodbye");
    std::cout << s3 << std::endl;

    //Comparison
    if(s1 == s2){
        std::cout << "s1 is equal to s2" << std::endl;
    }
    else if(s1 > s2){
        std::cout << "s1 is greater than s2" << std::endl;
    }
    else
        std::cout << "s1 is less than s2" << std::endl;

    //Removal
    s.erase(); // erase the whole string
    s.clear(); // erase the whole string
    s2.erase(0, 5); // erase the 1st 5 characters of the string

    //Search 
    auto pos = s3.find("World", 0); //return -1 if not found, else return the idx
    if (pos != std::string::npos){
        std::cout << "Found" << std::endl;
    }
}

std::string Combine(std::string const &first, std::string const &last){
    std::string fullname = first + last;
    return fullname;
}

int main16(){
    // char first[10];
    // char last[10];

    // std::cin.getline(first, 10);
    // std::cin.getline(last, 10);

    // const char * pFullName = Combine(first, last);
    // //Insert into database 
    // std::cout << pFullName << std::endl;
    // delete pFullName;

    std::string first;
    std::string last;
    std::getline(std::cin, first);
    std::getline(std::cin, last);
    std::string fullname = first + last;
    std::string fullname2 = Combine(first, last);
    //Insert into the database
    std::cout << fullname << std::endl;
    std::cout << fullname2 << std::endl;
    printf("%s", fullname.c_str()) //convert string to cstring to use printf
    return 0;
}

