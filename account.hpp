#pragma once
#include <iostream>
#include <string>

class Account{
    std::string name;
    long double balance;
    long int acc_num;
    static long int acc_num_generator;
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