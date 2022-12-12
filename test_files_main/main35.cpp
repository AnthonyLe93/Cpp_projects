# include <iostream>


/* Class template */


template <typename T, int size>
class Stack{
    T m_Buffer[size];
    int m_Top{-1};
public:
    Stack() = default;
    Stack(const Stack &obj){
        m_Top = obj.m_Top;
        for(int i = 0; i <= m_Top; ++i){
            m_Buffer[i] = obj.m_Buffer[i];
        }
    }
    void Push(const T &elem){
        m_Buffer[++m_Top] = elem;
    }

    void Pop();

    const T &Top() const{
        return m_Buffer[m_Top];
    }

    bool is_Empty(){
        return m_Top == -1;
    }

    static Stack Create();
};

template<typename T, int size>
void Stack<T, size>::Pop(){
    --m_Top;
}

template <typename T, int size>
Stack<T,size> Stack<T, size>::Create(){
    return Stack<T,size>();
}

int main35(){

    Stack<float, 10> s = Stack<float,10>::Create();
    s.Push(3.0f);
    s.Push(1.0f);
    s.Push(6.0f);
    s.Push(9.0f);
    auto s2(s);
    while(!s2.is_Empty()){
        std::cout << s2.Top() << " ";
        s2.Pop();
    }
    std::cout << std::endl;
    return 0;
}