#include <iostream>
#include "transaction.hpp"

void Transaction(Account *pAccount){
    std::cout << "Transaction started" << std::endl;
    std::cout << "Initial balance " << pAccount->GetBalance() << std::endl;
    pAccount -> Deposit(1000);
    pAccount -> AccumulateInterest();
    pAccount -> Withdraw(1500);
    std::cout << "Interest rate " << pAccount->GetInterestRate() << std::endl;
    std::cout << "Initial balance " << pAccount->GetBalance() << std::endl;
}