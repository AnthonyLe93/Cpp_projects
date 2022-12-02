#include <iostream>
#include "account.hpp"
#include <string>

int main(){
    
    Account acc("Anthony", 10000.00);
    //acc.PrintAccInfo();
    acc.Deposit(5000);
    acc.Withdraw(1000);
    return 0;
}
