# 🛒 Integrated Banking & Marketplace System

A comprehensive C++20 project implementing an object-oriented **online shopping marketplace** integrated with a **banking system**, managed by a central **System Controller**.

## 📊 System Architecture
![System Architecture](./UML.svg)

This project features:

- **Modern Memory Management**: Use of `shared_ptr`, `weak_ptr`, and `unique_ptr` for memory-safe ownership and clear dependency tracking.
- **Custom Exception Hierarchy**: Specific handling for `InsufficientFunds`, `AccountNotFound`, and `ProductIdNotFound`.
- **Smart Shopping Cart**: Uses `weak_ptr` aggregation in a `QuantityProduct` structure to separate product data from user-specific quantities.
- **Cross-Platform Build**: A universal `Makefile` designed to work seamlessly on both Windows and Linux environments.

---

## 📂 Project Structure

```text
├── App/                       # System controller and main entry
│   ├── include/               # SystemApp.hpp
│   └── src/                   # SystemApp.cpp, main.cpp
├── Banking_System/            # Accounts and Bank logic
│   ├── include/               # Bank.hpp, BankAccount.hpp, BankExceptions.hpp
│   └── src/                   # Bank.cpp, BankAccount.cpp, Checking/SavingsAccount.cpp
├── Online_MarketPlace/        # Products, Cart, and User logic
│   ├── include/               # OnlineMarketplace.hpp, User.hpp, Cart.hpp, etc.
│   └── src/                   # OnlineMarketplace.cpp, User.cpp, Cart.cpp, Product.cpp
├── Makefile                   # Universal build script
└── README.md
```

---

## 🛠️ Build & Run

The project requires a compiler with **C++20** support (GCC 10+ or Clang 10+).

### 🚀 Compilation

To compile the entire project, run the following command in the root directory:

```bash
make
```

### 🏃 Run the Program

Once compiled, launch the application:

```bash
# Windows
./system_app.exe

# Linux / macOS
./system_app
```

### 🧹 Cleaning the Build

To remove the executable and temporary build files:

```bash
make clean
```
