#ifndef ONLINEMARKETPLACE_HPP
#define ONLINEMARKETPLACE_HPP

#include <vector>
#include <memory>
#include <string>

#include "../../Banking_System/include/Bank.hpp"
#include "../../Banking_System/include/BankExceptions.hpp"
#include "Product.hpp"
#include "OnlineMarketplaceExceptions.hpp"
#include "User.hpp"

class OnlineMarketplace {
    private:
        std::vector<std::shared_ptr<Product>> m_products;
        std::unique_ptr<std::string> m_cardNumber;

        Product::Category menuForCategory() const;

    public:
        //OMP = online marketplace
        void addProductToOMP(const std::string& name, size_t price, Product::Category category) noexcept;
        void removeProductFromOMP(size_t productId);

        void connectBankCard(Bank& bank, const std::string& CardNumber);

        std::string getCardNumber() const { return *m_cardNumber; }

        void displayAllProducts() const;
        void displayCategory(Product::Category category) const;
        //void displayProductShoppersCount(size_t productId) const;

        void menu(Bank& bank);

        const std::shared_ptr<Product>& findProductById(size_t productId) const;
};

#endif