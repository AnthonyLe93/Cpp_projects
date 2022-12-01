# include <iostream>
// # define RED 0
// const int GREEN = 1;


/* Enumerator */

enum class Color{RED, GREEN, BLUE};
enum class TrafficLight : char {RED='r', GREEN='g', BLUE='g'};

void FillColor(Color color){
    //Fill background with some color
    if (color == Color::RED){
        //Paint with red color
        std::cout << "RED" << std::endl; 
    }
    else if (color == Color::GREEN){
        //Paint with green color
        std::cout << "GREEN" << std::endl; 
    }
    else if (color == Color::BLUE){
        //Paint with blue color
        std::cout << "BLUE" << std::endl; 
    }
    
}

int main14(){
    Color c = Color::RED;
    FillColor(c);
    FillColor(Color::GREEN);
    FillColor(static_cast<Color> (2));
    int x = static_cast<int>(Color::RED);

    return 0;
}