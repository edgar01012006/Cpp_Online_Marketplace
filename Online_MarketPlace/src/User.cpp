#include "../include/User.hpp"

size_t User::m_nextId = 0;

explicit User::User(const std::string& name)
    : m_name { name }, m_id { ++m_nextId } {}

void User::addProductToCart(OnlineMarketplace& om, size_t productId) {
    m_cart.addProductToCart(om, productId);
}

void User::removeProductFromCart(size_t productId) {
    m_cart.removeProductFromCart(productId);
}

void User::displayCart() const {
    m_cart.displayCart();
}

void User::getTotalPriceOfCart() const {
    m_cart.getTotalPriceOfCart();
}

void User::purchaseCart(Bank& bank, OnlineMarketplace& om) {
    double totalPrice = m_cart.getTotalPriceOfCart();
    try {
        bank.transfer(*m_cardNumber, om.getCardNumber(), totalPrice);
        cleanCart();
    } catch (const BankExceptions& ex) {
        std::cout << ex.what() << std::endl;
        std::cout << "Failed to purchase cart\n"; 
    }
}

void User::cleanCart() {
    m_cart.cleanCart();
}

void User::connectBankCard(Bank& bank, const std::string& CardNumber) {
    try {
        bank.findCardNumber(CardNumber);
        m_cardNumber = std::make_unique<std::string>(CardNumber);
    } catch (const BankExceptions& ex) {
        std::cout << ex.what() << "\n" 
                  << "Failed to connect Bank Card\n";
    }
}