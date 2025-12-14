#include "../include/CheckingAccount.hpp"

CheckingAccount::CheckingAccount(const std::string& name, double overdraftLimit)
    : BankAccount { name }, m_overdraftLimit { overdraftLimit } {} 

void CheckingAccount::withdraw(double amount) {
    if (amount < 0) {
        throw NegativeAmount("Can't withdraw negative amount");
    }
    if (amount > m_balance) {
        double balanceOverdraft =  m_balance + (m_balance * (m_overdraftLimit / 100));
        if (amount > balanceOverdraft) {
            throw InsufficientFunds("Can't withdraw; insufficient funds\n");
        }
        m_balance -= balanceOverdraft;
    } else {
        m_balance -= amount;
    }
}

void CheckingAccount::deposit(double amount) {
    if (amount < 0) {
        throw NegativeAmount("Can't deposit negative amount");
    }
    m_balance += amount;
}

void CheckingAccount::display() const {
    BankAccount::display();
    std::cout << "Overdraft limit: " << m_overdraftLimit << "%\n";
}