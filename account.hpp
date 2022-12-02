#pragma once
#include <iostream>
#include <string>

class Account{
protected:    
    std::string name;   
    long int acc_num;
    static long int acc_num_generator;
    long double balance;
public:
    Account(const std::string &name, long double balance);
    ~Account();
    const std::string GetName()const;
    float GetBalance()const;
    int GetAccNum()const;

    void AccumulateInterest();
    void Withdraw(long double amount);
    void Deposit(long double amount);
    float GetInterestRate()const;
    void PrintAccInfo();
};