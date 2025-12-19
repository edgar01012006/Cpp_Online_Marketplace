#include "../include/SystemApp.hpp"
#include <iostream>
#include <limits>

// Constructor: Uses initializer list to construct the User object
SystemApp::SystemApp(const std::string& userName) 
    : m_user(userName) {
    // Optional: Pre-load some products into the marketplace so it's not empty
    m_marketplace.addProductToOMP("Smartphone", 800, Product::Category::ELECTRONICS);
    m_marketplace.addProductToOMP("Jeans", 50, Product::Category::CLOTHING);
    m_marketplace.addProductToOMP("Desk Chair", 150, Product::Category::FURNITURE);
}

void SystemApp::displayMasterMenu() const {
    std::cout << "\n======================================\n"
              << "       CROSS-SYSTEM MASTER MENU       \n"
              << "======================================\n"
              << "1: Bank Administration (Create Accounts)\n"
              << "2: Marketplace Administration (Add Products)\n"
              << "3: User Shopping Mode (Cart & Checkout)\n"
              << "0: Exit Application\n"
              << "--------------------------------------\n"
              << "Current User: " << m_user.getName() << "\n"
              << "Choice: ";
}

void SystemApp::run() {
    int choice = -1;

    while (choice != 0) {
        displayMasterMenu();

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                // Enter the Bank's internal menu
                m_bank.menu();
                break;
            case 2:
                // Enter the Marketplace's internal menu
                m_marketplace.menu(m_bank);
                break;
            case 3:
                // Enter the User's personal menu
                m_user.menu(m_bank, m_marketplace);
                break;
            case 0:
                std::cout << "Exiting system. Goodbye!\n";
                break;
            default:
                std::cout << "Option not recognized.\n";
                break;
        }
    }
}