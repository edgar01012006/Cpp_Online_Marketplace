# 🛒 Integrated Banking & Marketplace System

A comprehensive C++ project implementing an object-oriented **online shopping marketplace** integrated with a **banking system**, managed by a central **System Controller**.  
Core operations—like managing bank accounts, marketplace products, and user shopping carts—are organized through well-structured classes to keep the system scalable and maintainable.

## 📊 System Architecture
![System Architecture](./UML.svg)

This project includes:
- **Clear OOP separation** between the Banking System, Online Marketplace, and App Controller
- **Use of `shared_ptr`, `weak_ptr`, and `unique_ptr`** for memory-safe ownership 
- **Custom exception handling** for invalid IDs, insufficient funds, and transactions 
- **Smart shopping list design** using `weak_ptr` aggregation (`QuantityProduct`) 
- **Unified Master Menu** to bridge the gap between banking administration and user shopping

---

## Project Structure

```text
├── Banking_System/
│   ├── include/
│   │   ├── Bank.hpp
│   │   ├── BankAccount.hpp
│   │   └── BankExceptions.hpp
│   └── src/
│       ├── Bank.cpp
│       ├── BankAccount.cpp
│       ├── CheckingAccount.cpp
│       └── SavingsAccount.cpp
├── Online_Marketplace/
│   ├── include/
│   │   ├── OnlineMarketplace.hpp
│   │   ├── User.hpp
│   │   ├── Cart.hpp
│   │   └── OnlineMarketplaceExceptions.hpp
│   └── src/
│       ├── OnlineMarketplace.cpp
│       ├── User.cpp
│       ├── Cart.cpp
│       └── Product.cpp
├── app/
│   ├── include/
│   │   └── SystemApp.hpp
│   └── src/
│       ├── SystemApp.cpp
│       └── main.cpp
├── UML.svg
└── README.md
# 🛒 Integrated Banking & Marketplace System

A comprehensive C++ project implementing an object-oriented **online shopping marketplace** integrated with a **banking system**, managed by a central **System Controller**.  
Core operations—like managing bank accounts, marketplace products, and user shopping carts—are organized through well-structured classes to keep the system scalable and maintainable.

## 📊 System Architecture
![System Architecture](./UML.svg)

This project includes:
- **Clear OOP separation** between the Banking System, Online Marketplace, and App Controller.
- **Use of `shared_ptr`, `weak_ptr`, and `unique_ptr`** for memory-safe ownership.
- **Custom exception handling** for invalid IDs, insufficient funds, and transactions.
- **Smart shopping list design** using `weak_ptr` aggregation (`QuantityProduct`).
- **Unified Master Menu** to bridge the gap between banking administration and user shopping.

---

## Project Structure

```text
├── Banking_System/
│   ├── include/
│   │   ├── Bank.hpp
│   │   ├── BankAccount.hpp
│   │   └── BankExceptions.hpp
│   └── src/
│       ├── Bank.cpp
│       ├── BankAccount.cpp
│       ├── CheckingAccount.cpp
│       └── SavingsAccount.cpp
├── Online_Marketplace/
│   ├── include/
│   │   ├── OnlineMarketplace.hpp
│   │   ├── User.hpp
│   │   ├── Cart.hpp
│   │   └── OnlineMarketplaceExceptions.hpp
│   └── src/
│       ├── OnlineMarketplace.cpp
│       ├── User.cpp
│       ├── Cart.cpp
│       └── Product.cpp
├── app/
│   ├── include/
│   │   └── SystemApp.hpp
│   └── src/
│       ├── SystemApp.cpp
│       └── main.cpp
├── UML.svg
└── README.md
```

---

## Build & Run

The project requires a compiler with **C++20** support.

### 🪟 Windows (Command Prompt / CMD)

```bash
g++ -std=c++20 app/src/main.cpp app/src/SystemApp.cpp Banking_System/src/Bank.cpp Banking_System/src/BankAccount.cpp Banking_System/src/CheckingAccount.cpp Banking_System/src/SavingsAccount.cpp Online_Marketplace/src/OnlineMarketplace.cpp Online_Marketplace/src/Product.cpp Online_Marketplace/src/User.cpp Online_Marketplace/src/Cart.cpp -I Banking_System/include -I Online_Marketplace/include -I app/include -o final_app.exe
```

### 🐧 Linux / macOS / PowerShell

```bash
g++ -std=c++20 app/src/main.cpp app/src/SystemApp.cpp Banking_System/src/*.cpp Online_Marketplace/src/*.cpp -I Banking_System/include -I Online_Marketplace/include -I app/include -o final_app
```

### Run the Program

```bash
# Windows
./final_app.exe

# Linux / macOS
./final_app
```