#include "../include/BankAccount.hpp"

long long int BankAccount::m_cardNumberCounter = 1000'0000'0000'0000;

BankAccount::BankAccount(const std::string& name) 
    : m_cardNumber { std::to_string(m_cardNumberCounter++) }, m_balance { 0.0 }, m_name { name } {}

BankAccount::BankAccount(BankAccount&& src) 
    : m_cardNumber { src.m_cardNumber }, m_balance { src.m_balance }, m_name { src.m_name } {
    src.m_cardNumber = "-1";
    src.m_balance = 0.0;
    src.m_name = "UNKNOWN";
}

BankAccount& BankAccount::operator=(BankAccount&& rhs) noexcept {
    if (this != &rhs) {
        m_cardNumber = rhs.m_cardNumber;
        m_balance = rhs.m_balance;
        m_name = rhs.m_name;
        rhs.m_cardNumber = "-1";
        rhs.m_balance = 0.0;
        rhs.m_name = "UNKNOWN";
    }
    return *this;
}

void BankAccount::display() const {
    std::cout << "Card number: " << m_cardNumber << "\n"
              << "Account balance: " << m_balance << "\n"
              << "Name: " << m_name << "\n";
}