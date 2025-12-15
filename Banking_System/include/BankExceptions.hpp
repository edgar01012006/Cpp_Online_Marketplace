#ifndef BANKEXCEPTIONS_HPP
#define BANKEXCEPTIONS_HPP

#include <stdexcept>
#include <string>

class BankExceptions : public std::runtime_error {
    public:
        BankExceptions(const std::string& message) : std::runtime_error(message) {}
};

class AccountNotFound : public BankExceptions {
    public:
        AccountNotFound(const std::string& message) : BankExceptions(message) {}
};

class InsufficientFunds : public BankExceptions {
    public:
        InsufficientFunds(const std::string& message) : BankExceptions(message) {}
};

class NegativeAmount : public BankExceptions {
    public:
        NegativeAmount(const std::string& message) : BankExceptions(message) {}
};

class CardNumberNotFound : public BankExceptions {
    public:
        CardNumberNotFound(const std::string& message) : BankExceptions(message) {}
};

#endif