#include <iostream>
#include <typeinfo>
#include "transaction.hpp"
#include "checking.hpp"

void Transaction(Account *pAccount){
    std::cout << "Transaction started" << std::endl;
    std::cout << "Initial balance " << pAccount->GetBalance() << std::endl;
    pAccount -> Deposit(1000);
    pAccount -> AccumulateInterest();
    // if (typeid(*pAccount) == typeid(Checking)){
    //     Checking * pChecking = static_cast<Checking*> (pAccount);
    //     // std::cout << pChecking -> GetMinBalance() <<std::endl;
    //     // std::cout << pChecking -> GetBalance() <<std::endl;
    //     if(pChecking -> GetBalance() < pChecking -> GetMinBalance()){
    //         std::cout << "Invalid transaction" << std::endl;
    //     }
    //     else{
    //         pAccount -> Withdraw(1500);
    //     }
    // }

    Checking *pChecking = dynamic_cast<Checking *>(pAccount);
    if (pChecking != nullptr){
        if(pChecking -> GetBalance() < pChecking -> GetMinBalance()){
            std::cout << "Invalid transaction" << std::endl;
        }
        else{
            pAccount -> Withdraw(1500);
        }
    }
    std::cout << "Interest rate " << pAccount->GetInterestRate() << std::endl;
    std::cout << "Initial balance " << pAccount->GetBalance() << std::endl;
}


void Transaction(Account & pAccount){
    std::cout << "Transaction started" << std::endl;
    std::cout << "Initial balance " << pAccount.GetBalance() << std::endl;
    pAccount.Deposit(1000);
    pAccount.AccumulateInterest();

    Checking &pChecking = dynamic_cast<Checking &>(pAccount);
    std::cout << "Minimum balance of checking" << pChecking.GetMinBalance() << std::endl;
    pAccount.Withdraw(1500);
    std::cout << "Interest rate " << pAccount.GetInterestRate() << std::endl;
    std::cout << "Initial balance " << pAccount.GetBalance() << std::endl;
}