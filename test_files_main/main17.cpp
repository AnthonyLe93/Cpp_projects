#include <iostream>
#include <sstream>

/* String stream */
int main17(){
    using namespace std;
    // int a{5};
    // int b{6};
    // int sum = a + b;

    

    // stringstream ss;
    // istringstream is;
    // ostringstream os;
    // ss << "Sum of " << a << " and " << b << " is " << sum << endl;
    // string s = ss.str();
    // cout << s << endl;

    // //ss.str("hkajsd") //accepts string
    // ss.str(""); // clear the string stream
    // ss << sum;
    // //auto ssum = ss.str();
    // auto ssum = std::to_string(sum);
    // cout << ssum << endl;
    string data = " 12 89 21";
    int a;
    stringstream ss;
    ss.str(data);
    while(ss >> a){ // return false when reaches end of stream
        cout << a << endl;
    }
    int x = stoi("999");
    return 0;
}