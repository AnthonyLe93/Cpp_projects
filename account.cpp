#include <iostream>
#include <string>
#include "account.hpp"



long int Account::acc_num_generator = 250219930;
Account::Account(const std::string &name, long double balance)
: name{name}, balance{balance} {
    acc_num =  ++acc_num_generator;
} 

const std::string Account::GetName()const{
    return name;
}

float Account::GetBalance()const{
    return balance;
}

int Account::GetAccNum()const{
    return acc_num;
}

void Account::AccumulateInterest(){

}

void Account::Withdraw(long double amount){
    if(balance < amount){
        std::cout << "You dont have enough balance" 
        "to perform this transaction" << std::endl;
    }
    else{
        balance -= amount;
        std::cout << "You have withdrawn: £" << amount << std::endl;
        std::cout << "The remaining balance: £" << balance << std::endl;
    }
}

void Account::Deposit(long double amount){
    balance += amount;
    std::cout << "You have deposited: £" << amount << std::endl;
    std::cout << "The new balance: £" << balance << std::endl;
}

float Account::GetInterestRate()const{
    return 0.0f;
}

void Account::PrintAccInfo(){
    std::cout << "The account holder name is " << name << "\n";
    std::cout << "The account number is " << acc_num << "\n";
    std::cout << "The account balance is £" << balance << std::endl;
}

Account::~Account(){
    
}

