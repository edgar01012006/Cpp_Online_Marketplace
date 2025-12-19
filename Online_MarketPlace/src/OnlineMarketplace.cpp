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

Product::Category OnlineMarketplace::menuForCategory() const {
    int input;
    std::cout << "\nSelect a Category:\n"
              << "0: None\n"
              << "1: Clothing\n"
              << "2: Furniture\n"
              << "3: Electronics\n"
              << "Your choice: ";
    std::cin >> input;

    switch(input) {
        case 1: return Product::Category::CLOTHING;
        case 2: return Product::Category::FURNITURE;
        case 3: return Product::Category::ELECTRONICS;
        default: return Product::Category::NONE;
    }
}

void OnlineMarketplace::menu(Bank& bank) {
    int input = 1;
    std::string name;
    size_t price;
    size_t productId;
    std::string cardNumber;

    while (input != 0) {
        std::cout << "\n--- Online Marketplace Menu ---\n"
                  << "0: Exit\n" 
                  << "1: Connect bank card\n"
                  << "2: Get marketplace card number\n"
                  << "3: Add product to marketplace\n"
                  << "4: Remove product from marketplace\n"
                  << "5: Display all products\n"
                  << "6: Display products by category\n\n";
        
        std::cout << "Your input: "; 
        std::cin >> input;
        std::cout << "\n";

        switch(input) {
            case 0:
                return;
            case 1:
                std::cout << "Enter the card number: ";
                std::cin >> cardNumber;
                connectBankCard(bank, cardNumber);
                break;
            case 2:
                try {
                    std::cout << "Marketplace Card: " << getCardNumber() << "\n";
                } catch (...) {
                    std::cout << "No card connected yet.\n";
                }
                break;
            case 3:
                std::cout << "Enter product name: ";
                std::cin.ignore(); // Clean buffer
                std::getline(std::cin, name);
                std::cout << "Enter price: ";
                std::cin >> price;
                addProductToOMP(name, price, menuForCategory());
                std::cout << "Product added successfully.\n";
                break;
            case 4:
                std::cout << "Enter Product ID to remove: ";
                std::cin >> productId;
                try {
                    removeProductFromOMP(productId);
                    std::cout << "Product " << productId << " removed.\n";
                } catch (const OnlineMarketplaceExceptions& ex) {
                    std::cout << "Error: " << ex.what() << "\n";
                }
                break;
            case 5:
                std::cout << "--- All Available Products ---\n";
                displayAllProducts();
                break;
            case 6:
                displayCategory(menuForCategory());
                break;
            default:
                std::cout << "Invalid input.\n";
                break;
        }
    }
}