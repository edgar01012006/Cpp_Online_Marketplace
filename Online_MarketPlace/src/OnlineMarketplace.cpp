#include "../include/OnlineMarketplace.hpp"

void OnlineMarketplace::addProductToOMP(const std::string& name, size_t price, Product::Category category) noexcept {
    m_products.emplace_back(std::make_shared<Product>(name, price, category));
}

void OnlineMarketplace::removeProductFromOMP(size_t productId) {
    for (int i = 0; i < m_products.size(); ++i) {
        if (m_products[i]->getId() == productId) {
            m_products.erase(m_products.begin() + i);
            return;
        }
    }
    throw ProductIdNotFound("Product Id not found");
}

void OnlineMarketplace::connectBankCard(Bank& bank, const std::string& CardNumber) {
    try {
        bank.findCardNumber(CardNumber);
        m_cardNumber = std::make_unique<std::string>(CardNumber);
    } catch (const BankExceptions& ex) {
        std::cout << ex.what() << std::endl;
        std::cout << "Failed to connect Bank Card\n";
    }
}

void OnlineMarketplace::displayAllProducts() const {
    for (int i = 0; i < m_products.size(); ++i) {
        std::cout << *m_products[i] << "\n";
    }
}

void OnlineMarketplace::displayCategory(Product::Category category) const {
    for (int i = 0; i < m_products.size(); ++i) {
        if (m_products[i]->getCategory() == category) {
            std::cout << *m_products[i] << "\n";
        }
    }
}

const std::shared_ptr<Product>& OnlineMarketplace::findProductById(size_t productId) const {
    for (int i = 0; i < m_products.size(); ++i) {
        if (m_products[i]->getId() == productId) {
            return m_products[i];
        }
    }
    throw ProductIdNotFound("Product Id not found");
}