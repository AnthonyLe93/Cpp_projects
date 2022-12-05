#include <iostream>
#include "account.hpp"
#include "saving.hpp"
#include "checking.hpp"
#include <string>

int main(){
    
    Account acc("Anthony", 10000.00);
    //acc.PrintAccInfo();
    acc.Deposit(5000);
    acc.Withdraw(1000);

    Saving acc_saving("Anthony_saver", 20000.00, 0.1f);
    //acc_saving.PrintAccInfo();
    acc_saving.Deposit(1000);
    acc_saving.Withdraw(235.13);

    Checking acc_checking("Anthony_checking", 100000.00);
    acc_checking.PrintAccInfo();
    acc_checking.Deposit(10000);
    acc_checking.Withdraw(109990);

    return 0;
}
