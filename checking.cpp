#include <iostream>
#include "checking.hpp"
#include <string>

// Checking::Checking(const std::string &name, long double balance)
// :Account{name, balance}{
// }

void Checking::Withdraw(long double amount){
    if((balance - amount) > 50.00){
        Account::Withdraw(amount);
    }
    else{
        std::cout << "Invalid amount" << std::endl;
    }
}

Checking::~Checking(){

}
 