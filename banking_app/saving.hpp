#pragma once
#include <iostream>
#include "account.hpp"

class Saving : public Account{
    float rate;
public:
    Saving(const std::string &name, long double balance, float rate);
    void AccumulateInterest();
    float GetInterestRate()const;
    void PrintAccInfo();
    ~Saving();
};