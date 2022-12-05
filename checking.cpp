#include <iostream>
#include "checking.hpp"
#include <string>

// Checking::Checking(const std::string &name, long double balance)
// :Account{name, balance}{
// }

Checking::Checking(const std::string &name, long double balance, float minBalance)
:Account(name, balance), min_balance(minBalance){

}

void Checking::Withdraw(long double amount){
    if((balance - amount) > min_balance){
        Account::Withdraw(amount);
    }
    else{
        std::cout << "Invalid amount" << std::endl;
    }
}
float Checking::GetMinBalance(){
    return min_balance;
}

float Checking::SetMinBalance(float amount){
    return min_balance = amount;
}

Checking::~Checking(){
    std::cout <<"~Saving()" << std::endl;
}
 