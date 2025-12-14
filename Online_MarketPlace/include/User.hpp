#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "Cart.hpp"

class User {
    private:
        std::string m_name;
        Cart cart;
        std::unique_ptr<std::string> m_cardNumber;
        size_t m_id;
        static size_t m_nextId;

    public:
        User(const std::string& name);
        User(const User& src) = delete;
        User& operator=(const User& rhs) = delete;
        User(User&& src);
        User& operator=(User&& rhs);

        void addProductToCart(size_t productId);
        void removeProductFromCart(size_t productId);

        void displayCart() const;
        void getTotalPriceOfCart() const;

        void purchaseCart();
        void cleanCart();

        void connectBankCard(std::string bankCardNumber);

        std::string getName() const;
        double getBalance() const;
        size_t getId() const;
        
        size_t getId() const { return m_id; }
        std::string getName() const { return m_name; }
        
};

#endif