#include <iostream>

/* User defined literals */


class Distance{
    long double m_Kilometres;
public:
    Distance(long double km) : m_Kilometres{km}{

    }

    long double GetKm()const{
        return m_Kilometres;
    }

    void SetKm(long double val){
        m_Kilometres = val;
    }
};

Distance operator"" _miles(long double val){
    return Distance{val * 1.6};
}
Distance operator"" _metres(long double val){
    return Distance{val / 1000};
}

int main18() {
    Distance dist{32.0_miles}; //converted to km through user-defined literals.
    Distance dist2{7123.0_metres};

    std::cout << dist2.GetKm() << std::endl;
    return 0;
}