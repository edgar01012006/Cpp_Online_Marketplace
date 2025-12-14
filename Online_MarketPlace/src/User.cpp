#include "../include/User.hpp"
#include "../include/OnlineMarketplaceExceptions.hpp"

size_t User::m_nextId = 0;

User::User(const std::string& name)
    : m_name { name }, m_balance { 0.0 }, m_id { ++m_nextId } {}

void User::deposit(double amount) {
    if (amount < 0) {
        throw NegativeAmount("Cant deposit negative amount");
    }
    m_balance += amount;
}

void User::withdraw(double amount) {
    if (amount < 0) {
        throw NegativeAmount("Cant withdraw negative amount");
    }
    if (amount > m_balance) {
        throw InsufficientFunds("Insufficient funds");
    }
    m_balance -= amount;
}