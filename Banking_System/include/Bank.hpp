#ifndef BANK_HPP
#define BANK_HPP

#include <memory>
#include <vector>
#include <string>

#include "BankAccount.hpp"
#include "BankExceptions.hpp"
#include "CheckingAccount.hpp"
#include "SavingsAccount.hpp"

class Bank {
    public:
        void withdraw(const std::string& cardNumber, double amount);
        void deposit(const std::string& cardNumber, double amount);

        void createCheckingAccount(const std::string& name);
        void createSavingsAccount(const std::string& name);

        void transfer(const std::string& cardNumber1, const std::string& cardNumber2, double amount);

        void findCardNumber(const std::string& cardNumber) const;

        void display() const;

        void menu();

    private:
        BankAccount* findCardAccount(const std::string& cardNumber) const;

        std::vector<std::unique_ptr<BankAccount>> m_bankAccounts;
};

#endif