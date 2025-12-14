#ifndef CHECKINGACCOUNT_HPP
#define CHECKINGACCOUNT_HPP

#include "BankAccount.hpp"
#include "BankExceptions.hpp"

class CheckingAccount : public BankAccount {
    public:
        CheckingAccount(const std::string& name, double overdraftLimit = 20.0);

        void withdraw(double amount) override;
        void deposit(double amount) override;
        
        void display() const override;

    private:
        double m_overdraftLimit; // in %
};

#endif