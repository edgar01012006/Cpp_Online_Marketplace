#include "../include/SavingsAccount.hpp"

SavingsAccount::SavingsAccount(const std::string& name, double interestRate) 
    : BankAccount { name }, m_interestRate { interestRate } {}

void SavingsAccount::withdraw(double amount) {
    if (amount < 0) {
        throw NegativeAmount("Can't withdraw negative amount");
    }
    if (amount > m_balance) {
        throw InsufficientFunds("Can't withdraw; insufficient funds\n");
    }
    m_balance -= amount;
}

void SavingsAccount::deposit(double amount) {
    if (amount < 0) {
        throw NegativeAmount("Can't deposit negative amount");
    }
    m_balance += amount;
}

void SavingsAccount::display() const {
    BankAccount::display();
    std::cout << "Interest rate: " << m_interestRate << "%\n";
}