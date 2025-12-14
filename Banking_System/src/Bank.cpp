#include "../include/Bank.hpp"

BankAccount* Bank::findCardNumber(const std::string& cardNumber) {
    for (auto& bankAccount: m_bankAccounts) {
        if (bankAccount->getCardNumber() == cardNumber) {
            return bankAccount.get();
        }
    }
    throw AccountNotFound("Account not found");
}

void Bank::withdraw(const std::string& cardNumber, double amount) {
    BankAccount* bankAccount = findCardNumber(cardNumber);
    bankAccount->withdraw(amount);
}

void Bank::deposit(const std::string& cardNumber, double amount) {
    BankAccount* bankAccount = findCardNumber(cardNumber);
    bankAccount->deposit(amount);
}

void Bank::createCheckingAccount(const std::string& name) {
    m_bankAccounts.emplace_back(std::make_unique<CheckingAccount>(name));
}

void Bank::createSavingsAccount(const std::string& name) {
    m_bankAccounts.emplace_back(std::make_unique<SavingsAccount>(name));
}

void Bank::transfer(const std::string& cardNumber1, const std::string& cardNumber2, double amount) {
    BankAccount* bankAccount1 = findCardNumber(cardNumber1);
    BankAccount* bankAccount2 = findCardNumber(cardNumber2);
    bankAccount1->withdraw(amount);
    bankAccount2->deposit(amount);
}

void Bank::display() const {
    for (auto& bankAccount: m_bankAccounts) {
        bankAccount->display();
        std::cout << "\n";
    }
}


// void Bank::menu() {
//     int input = 1;
//     std::string name; // 1, 2
//     std::string cardNumber1; // 3, 4, 5
//     std::string cardNumber2; // 5
//     double amount; // 3, 4, 5

//     while (input != 0) {
//         std::cout << "\n0: Exit\n" 
//                   << "1: create Checking account\n"
//                   << "2: create Savings account\n"
//                   << "3: withdraw\n"
//                   << "4: deposit\n"
//                   << "5: transfer\n"
//                   << "6: display all accounts\n\n";
        
//         std::cout << "Your input: "; 
//         std::cin >> input;
//         std::cout << "\n";
//         switch(input) {
//             case 0:
//                 return;
//             case 1:
//                 std::cout << "Enter the name\n";
//                 std::cin >> name;
//                 createCheckingsAccount(name);
//                 break;
//             case 2:
//                 std::cout << "Enter the name\n";
//                 std::cin >> name;
//                 createSavingsAccount(name);
//                 break;
//             case 3:
//                 std::cout << "Enter the card number\n";
//                 std::cin >> cardNumber1;
//                 std::cout << "Enter the amount\n";         
//                 std::cin >> amount;
//                 withdraw(cardNumber1, amount);
//                 break;
//             case 4:
//                 std::cout << "Enter the card number\n";
//                 std::cin >> cardNumber1;
//                 std::cout << "Enter the amount\n"; 
//                 std::cin >> amount;
//                 deposit(cardNumber1, amount);
//                 break;
//             case 5:
//                 std::cout << "Enter the card number you will transfer from\n";
//                 std::cin >> cardNumber1;
//                 std::cout << "Enter the card number you will transfer to\n";
//                 std::cin >> cardNumber2;
//                 std::cout << "Enter the amount you would like to transfer\n";
//                 std::cin >> amount;
//                 transfer(cardNumber1, cardNumber2, amount);
//                 break;
//             case 6:
//                 display();
//                 break;
//             default:
//                 break;
//         }
//     }
// }