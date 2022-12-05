#include <iostream>
#include <string>
#include <typeinfo>
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
    // Account *acc_saving = new Saving("Anthony_saver", 20000.00, 0.1f);
    // Transaction(&acc_saving);
    // std::cout << "Size of Account " << sizeof(Account) << std::endl;
    // delete acc_saving;

    Checking acc_ch {"Emily", 1000, 50};
    // Account &ca = acc_ch; //Upcasting a child class to base class (must use pointer or ref)

    // Checking & pChecking = static_cast<Checking &>(ca);//Downcasting a base class to child class

    // std::cout << acc_ch.SetMinBalance(11.123) << std::endl;
    // std::cout << acc_ch.GetMinBalance() << std::endl;
    Transaction(&acc_ch);

    Saving acc_save {"Emily_saver", 2000, 0.05f};
    try{ 
        Transaction(acc_save);
    }catch(std::exception &ex){
        std::cout << "Exception: " << ex.what() << '\n';
    }

    return 0;
}
