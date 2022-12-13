#include <iostream>
#include <vector>
#include <list>

/* Typedef, type alias and alias templates */
const char * GetErrorMessage(int errorNo){
    return "Empty";
}
// typedef const char *(*PFN)(int);
using PFN = const char *(*)(int);
void ShowError(PFN pfn){

}
// typedef std::vector<std::list<std::string>> Names;
// using Names = std::vector<std::list<std::string>>;

template<typename T>
using Names = std::vector<std::list<T>>;
int main38(){
    Names<std::string> names;
    Names<Names<std::string>> nnames;
    PFN pfn = GetErrorMessage;
    ShowError(pfn);
    return 0;
}