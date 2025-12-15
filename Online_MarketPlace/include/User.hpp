#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <memory>

#include "../../Banking_System/include/Bank.hpp"
#include "../../Banking_System/include/BankExceptions.hpp"
#include "Cart.hpp"
#include "OnlineMarketplace.hpp"

class User {
    private:
        std::string m_name;
        Cart m_cart;
        std::unique_ptr<std::string> m_cardNumber;
        size_t m_id;
        static size_t m_nextId;

    public:
        explicit User(const std::string& name);
        User(const User& src) = delete;
        User& operator=(const User& rhs) = delete;
        User(User&& src) noexcept = default;
        User& operator=(User&& rhs) noexcept = default;

        void addProductToCart(OnlineMarketplace& om, size_t productId);
        void removeProductFromCart(size_t productId);

        void displayCart() const;
        void getTotalPriceOfCart() const;

        void purchaseCart(Bank& bank, OnlineMarketplace& om);
        void cleanCart();

        void connectBankCard(Bank& bank, const std::string& CardNumber); // dependency with bank

        std::string getName() const { return m_name; }
        size_t getId() const { return m_id; }
        
};

#endif