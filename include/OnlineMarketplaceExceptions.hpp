#ifndef ONLINEMARKETPLACEEXCEPTIONS_HPP
#define ONLINEMARKETPLACEEXCEPTIONS_HPP

#include <stdexcept>
#include <string>

class OnlineMarketplaceExceptions : public std::runtime_error {
    public:
        OnlineMarketplaceExceptions(const std::string& msg) : std::runtime_error { msg } {}
};

class InvalidPrice : public OnlineMarketplaceExceptions {
    public:
        InvalidPrice(const std::string& msg) : OnlineMarketplaceExceptions { msg } {}
};

class InvalidName : public OnlineMarketplaceExceptions {
    public:
        InvalidName(const std::string& msg) : OnlineMarketplaceExceptions { msg } {}
};

class ProductIdNotFound : public OnlineMarketplaceExceptions {
    public:
        ProductIdNotFound(const std::string& msg) : OnlineMarketplaceExceptions { msg } {}
};

class InsufficientFunds : public OnlineMarketplaceExceptions {
    public:
        InsufficientFunds(const std::string& msg) : OnlineMarketplaceExceptions { msg } {}
};

class NegativeAmount : public OnlineMarketplaceExceptions {
    public:
        NegativeAmount(const std::string& msg) : OnlineMarketplaceExceptions { msg } {}
};


#endif