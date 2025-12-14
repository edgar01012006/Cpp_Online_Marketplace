#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <string>
#include <iostream>

class BankAccount {
    public:
        BankAccount(const std::string& name);
        BankAccount(const BankAccount&) = delete;
        BankAccount& operator=(const BankAccount&) = delete;
        BankAccount(BankAccount&& src) noexcept;
        BankAccount& operator=(BankAccount&& rhs) noexcept;
        virtual ~BankAccount() {};

        virtual void withdraw(double amount) = 0;
        virtual void deposit(double amount) = 0;
        
        virtual void display() const = 0;

        std::string getCardNumber() const { return m_cardNumber; }
        double getBalance() const { return m_balance; }

    protected:
        std::string m_cardNumber;
        double m_balance;
        std::string m_name;

    private:
        static long long int m_cardNumberCounter;
};

#endif