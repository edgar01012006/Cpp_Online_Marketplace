#include "../include/User.hpp"
#include "../include/OnlineMarketplace.hpp"
#include "../../Banking_System/include/Bank.hpp"

size_t User::m_nextId = 0;

User::User(const std::string& name)
    : m_name { name }, m_id { ++m_nextId } {}

void User::addProductToCart(OnlineMarketplace& om, size_t productId) {
    try {
        m_cart.addProductToCart(om, productId);
    }
    catch (const OnlineMarketplaceExceptions& ex) {
        std::cout << ex.what() << std::endl;
        std::cout << "Failed to add the product to thecart\n";
    }
}

void User::removeProductFromCart(size_t productId) {
    try {
        m_cart.removeProductFromCart(productId);
    }
    catch (const OnlineMarketplaceExceptions& ex) {
        std::cout << ex.what() << std::endl;
        std::cout << "Failed to remove the product from the cart\n";
    }
}

void User::displayCart() const {
    m_cart.displayCart();
}

double User::getTotalPriceOfCart() const {
    return m_cart.getTotalPriceOfCart();
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
        std::cout << ex.what() << std::endl;
        std::cout << "Failed to connect Bank Card\n";
    }
}

void User::menu(Bank& bank, OnlineMarketplace& om) {
    int input = -1;
    size_t productId;
    std::string cardNumber;

    while (input != 0) {
        std::cout << "\n===== User Menu: " << m_name << " (ID: " << m_id << ") =====\n"
                  << "0: Back to Master Menu\n"
                  << "1: Connect/Change Bank Card\n"
                  << "2: View Marketplace Products\n"
                  << "3: Add Product to Cart\n"
                  << "4: View My Cart & Total Price\n"
                  << "5: Remove Product from Cart\n"
                  << "6: Checkout (Purchase Cart)\n"
                  << "7: Empty Cart\n"
                  << "Your input: ";

        if (!(std::cin >> input)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        try {
            switch (input) {
                case 0:
                    return;

                case 1:
                    std::cout << "Enter your Card Number: ";
                    std::cin >> cardNumber;
                    connectBankCard(bank, cardNumber);
                    std::cout << "Card connected successfully!\n";
                    break;

                case 2:
                    std::cout << "--- Marketplace Stock ---\n";
                    om.displayAllProducts();
                    break;

                case 3:
                    std::cout << "Enter the Product ID to add: ";
                    std::cin >> productId;
                    addProductToCart(om, productId);
                    std::cout << "Product added to cart.\n";
                    break;

                case 4:
                    std::cout << "--- Your Shopping Cart ---\n";
                    displayCart();
                    std::cout << "--------------------------\n";
                    std::cout << "Total Price: $" << getTotalPriceOfCart() << "\n";
                    break;

                case 5:
                    std::cout << "Enter Product ID to remove: ";
                    std::cin >> productId;
                    removeProductFromCart(productId);
                    std::cout << "Product removed from cart.\n";
                    break;

                case 6:
                    if (!m_cardNumber) {
                        std::cout << "Error: You must connect a bank card before purchasing!\n";
                    } else {
                        std::cout << "Attempting to purchase cart for $" << getTotalPriceOfCart() << "...\n";
                        purchaseCart(bank, om);
                        std::cout << "Purchase successful! Your cart is now empty.\n";
                    }
                    break;

                case 7:
                    cleanCart();
                    std::cout << "Cart emptied.\n";
                    break;

                default:
                    std::cout << "Invalid option.\n";
                    break;
            }
        } 
        catch (const OnlineMarketplaceExceptions& ex) {
            std::cout << "\n[MARKETPLACE ERROR]: " << ex.what() << "\n";
        }
        catch (const BankExceptions& ex) {
            std::cout << "\n[BANKING ERROR]: " << ex.what() << "\n";
        }
    }
}