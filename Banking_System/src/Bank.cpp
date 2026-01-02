#include "Bank.hpp"

void Bank::withdraw(const std::string& cardNumber, double amount) {
    BankAccount* bankAccount = findCardAccount(cardNumber);
    bankAccount->withdraw(amount);
}

void Bank::deposit(const std::string& cardNumber, double amount) {
    BankAccount* bankAccount = findCardAccount(cardNumber);
    bankAccount->deposit(amount);
}

void Bank::createCheckingAccount(const std::string& name) {
    m_bankAccounts.emplace_back(std::make_unique<CheckingAccount>(name));
}

void Bank::createSavingsAccount(const std::string& name) {
    m_bankAccounts.emplace_back(std::make_unique<SavingsAccount>(name));
}

void Bank::transfer(const std::string& cardNumber1, const std::string& cardNumber2, double amount) {
    BankAccount* bankAccount1 = findCardAccount(cardNumber1);
    BankAccount* bankAccount2 = findCardAccount(cardNumber2);
    bankAccount1->withdraw(amount);
    bankAccount2->deposit(amount);
}

BankAccount* Bank::findCardAccount(const std::string& cardNumber) const {
    for (auto& bankAccount: m_bankAccounts) {
        if (bankAccount->getCardNumber() == cardNumber) {
            return bankAccount.get();
        }
    }
    throw AccountNotFound("Account not found");
}

void Bank::findCardNumber(const std::string& cardNumber) const {
    for (auto& bankAccount: m_bankAccounts) {
        if (bankAccount->getCardNumber() == cardNumber) {
            return;
        }
    }
    throw CardNumberNotFound("Card Number not found");
}

void Bank::display() const {
    for (auto& bankAccount: m_bankAccounts) {
        bankAccount->display();
        std::cout << "\n";
    }
}


void Bank::menu() {
    int input = -1;
    std::string name;
    std::string cardNumber1, cardNumber2;
    double amount;

    while (input != 0) {
        std::cout << "\n--- Bank Management Menu ---\n"
                  << "0: Exit to Master Menu\n" 
                  << "1: Create Checking Account\n"
                  << "2: Create Savings Account\n"
                  << "3: Withdraw\n"
                  << "4: Deposit\n"
                  << "5: Transfer\n"
                  << "6: Display All Accounts\n"
                  << "Your input: ";

        // Basic check to ensure we get a number for the menu
        if (!(std::cin >> input)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        
        std::cout << "\n";
        
        // Use a single try-catch block for the whole switch to handle BankExceptions
        try {
            switch(input) {
                case 0:
                    return;

                case 1:
                case 2:
                    std::cout << "Enter the full name for the account: ";
                    std::cin.ignore(); // Clear the 'Enter' from the menu input
                    std::getline(std::cin, name); // Now handles spaces in names!
                    
                    if (input == 1) createCheckingAccount(name);
                    else createSavingsAccount(name);
                    
                    std::cout << "Account created successfully.\n";
                    break;

                case 3:
                    std::cout << "Enter the card number: ";
                    std::cin >> cardNumber1;
                    std::cout << "Enter the amount: ";
                    std::cin >> amount;
                    withdraw(cardNumber1, amount);
                    std::cout << "Withdrawal successful.\n";
                    break;

                case 4:
                    std::cout << "Enter the card number: ";
                    std::cin >> cardNumber1;
                    std::cout << "Enter the amount: ";
                    std::cin >> amount;
                    deposit(cardNumber1, amount);
                    std::cout << "Deposit successful.\n";
                    break;

                case 5:
                    std::cout << "Enter source card number: ";
                    std::cin >> cardNumber1;
                    std::cout << "Enter destination card number: ";
                    std::cin >> cardNumber2;
                    std::cout << "Enter amount to transfer: ";
                    std::cin >> amount;
                    transfer(cardNumber1, cardNumber2, amount);
                    std::cout << "Transfer successful.\n";
                    break;

                case 6:
                    display();
                    break;

                default:
                    std::cout << "Option not recognized.\n";
                    break;
            }
        } 
        // This is the magic part! It catches your custom errors 
        // like InsufficientFunds or AccountNotFound.
        catch (const BankExceptions& ex) {
            std::cout << "\n[BANK ERROR]: " << ex.what() << "\n";
        }
        catch (const std::exception& ex) {
            std::cout << "\n[SYSTEM ERROR]: " << ex.what() << "\n";
        }
    }
}