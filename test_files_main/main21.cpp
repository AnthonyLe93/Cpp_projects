#include <iostream>
#include <vector>

/* Dynamic array: vector */
int main21(){
    int arr[10];
    int *ptr = new int[10];
    for (int i = 0; i < 10; ++i){
        ptr[i] = i * 10;
    }

    std::vector<int> data{1,2,3};
    for (int i = 0; i < 10; ++i){
        data.push_back(i * 10);
    }
    //Access
    data[0] = 100;
    // for(int i = 0; i < data.size(); ++i){
    //     std::cout << data[i] << " ";
    // }
    // std::cout << std::endl;

    for(auto x : data){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    auto it = data.begin();
    std::cout << *it << std::endl;
    ++it;
    --it;
    it = it + 5;
    //Delete
    it = data.begin();
    data.erase(it);
    for(auto x : data){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    //Insert
    data.insert(it + 5, 999);
        for(auto x : data){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}