#pragma once
#include <iostream>
#include "account.hpp"

class Checking : public Account{   
public:
    using Account::Account; //New C++11 feature to call base class constructor
    //Checking(const std::string &name, long double balance);
    void Withdraw(long double amount);
    ~Checking();
};