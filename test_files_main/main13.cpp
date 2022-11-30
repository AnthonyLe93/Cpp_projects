#include <cstdlib>
#include <iostream>
#include <memory>

/* Make function with smart pointers*/
class Point{
    
public:
    Point(int x, int y){

    }
};

int main13(){
    {
        auto p = std::make_unique<int>(5);
        auto pt = std::make_unique<Point>(3,5);
        auto pArr = std::make_unique<int[]>(5);
        pArr[0] = 0;
    }

    {
        auto p = std::make_shared<int>(5);
        auto pt = std::make_shared<Point>(3,5);

    }
    return 0;
}