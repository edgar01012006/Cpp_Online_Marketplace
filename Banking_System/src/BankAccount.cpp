#include "../include/BankAccount.hpp"

long long int BankAccount::m_cardNumberCounter = 1000'0000'0000'0000;

BankAccount::BankAccount(const std::string& name) 
    : m_cardNumber { std::to_string(m_cardNumberCounter++) }, m_balance { 0.0 }, m_name { name } {}

void BankAccount::display() const {
    std::cout << "Card number: " << m_cardNumber << "\n"
              << "Account balance: " << m_balance << "\n"
              << "Name: " << m_name << "\n";
}