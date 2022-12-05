#pragma once
#include <iostream>
#include "account.hpp"

class Checking : public Account{ 
    float min_balance = 50.f;  // Default min balance
public:
    //using Account::Account; //New C++11 feature to call base class constructor
    Checking(const std::string &name, long double balance, float minBalance);
    void Withdraw(long double amount);
    float GetMinBalance()const;
    float SetMinBalance(const float &amount);
    bool CheckMinBalance(const float &balance);
    ~Checking();
};