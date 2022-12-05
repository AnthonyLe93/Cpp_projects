#include <iostream>
#include <string>
#include "account.hpp"
#include "saving.hpp"
#include "checking.hpp"
#include "transaction.hpp"

int main(){
    
    // Account acc("Anthony", 10000.00);
    // //acc.PrintAccInfo();
    // acc.Deposit(5000);
    // acc.Withdraw(1000);

    // Saving acc_saving("Anthony_saver", 20000.00, 0.1f);
    // //acc_saving.PrintAccInfo();
    // acc_saving.Deposit(1000);
    // acc_saving.Withdraw(235.13);

    // Checking acc_checking("Anthony_checking", 10000.00);
    // Transaction(&acc_checking);
    Account *acc_saving = new Saving("Anthony_saver", 20000.00, 0.1f);
    //Transaction(&acc_saving);
    //std::cout << "Size of Account " << sizeof(Account) << std::endl;
    delete acc_saving;
    return 0;
}
