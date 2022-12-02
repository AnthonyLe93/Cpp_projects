#include <iostream>
#include "saving.hpp"
#include <string>

Saving::Saving(const std::string &name, long double balance, float rate)
:Account{name, balance}, rate{rate}{

}


void Saving::AccumulateInterest(){
    balance += (balance*rate);
}

float Saving::GetInterestRate()const{
    return rate;
}


void Saving::PrintAccInfo(){
    std::cout << "The account holder name is " << name << "\n";
    std::cout << "The account number is " << acc_num << "\n";
    std::cout << "The interest rate is " << rate << "\n";
    std::cout << "The account balance is £" << balance << std::endl;
}
Saving::~Saving(){

}
 