#include <iostream>
/* Abstract classes */
#pragma region Override

class Document{
public:
    virtual void Serialize(float version) = 0; //pure vitual, implementation is left 
                                               //for child classes 
};

class Text: public Document{
public:
    void Serialize(float version)override final{
        std::cout << "Text::Serialize" << std::endl;
    }
};

class RichText: public Text{
    // cannot override because the function is final in base
    /* void Serialize(float version)override {
            std::cout << "RichText::Serialize" << std::end;
        }
    */
};

class XML : public Document{
public: 
    void Serialize(float version)override{
        std::cout << "XML::Serialize" << std::endl;
    }
};

void Write(Document * p){
    p -> Serialize(1.23f);
}


#pragma endregion



int main24(){
    // Text t;
    // Document &doc = t;
    // doc.Serialize(1.2f);

    XML xml;
    Write(&xml);
    return 0;
}