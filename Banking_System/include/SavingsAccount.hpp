#ifndef SAVINGSACCOUNT_HPP
#define SAVINGSACCOUNT_HPP

#include "BankAccount.hpp"
#include "BankExceptions.hpp"

class SavingsAccount : public BankAccount {
    public:
        SavingsAccount(const std::string& name, double interestRate = 1.0);

        void withdraw(double amount) override;
        void deposit(double amount) override;
        
        void display() const override;

    private:
        double m_interestRate; // in %
};

#endif