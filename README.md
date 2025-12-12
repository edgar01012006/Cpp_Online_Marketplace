# 🛒 Online Marketplace System — Product, User & Shopping List Management

A C++ project implementing an object-oriented **online shopping marketplace**, where products, users, and shopping lists are modeled using clean abstractions.  
Core operations—like adding/removing products, managing shopping lists, performing purchases, and validating transactions—are organized through well-structured classes to keep the system scalable and maintainable.

This project includes:

- Clear OOP separation between marketplace, product, user, and shopping list  
- Use of `shared_ptr`, `weak_ptr`, and `unique_ptr` for memory-safe ownership  
- Custom exception handling for invalid IDs, prices, names, and transactions  
- Smart shopping list design using `weak_ptr` aggregation (`QuantityProduct`)  
- Easy expandability for new marketplace features  

---

## Project Structure

```
├── main.cpp
├── include/
│   ├── Product.hpp
│   ├── OnlineMarketplace.hpp
│   ├── ShoppingList.hpp
│   ├── User.hpp
│   └── CustomExceptions.hpp
├── src/
│   ├── Product.cpp
│   ├── OnlineMarketplace.cpp
│   ├── ShoppingList.cpp
│   └── User.cpp
└── README.md
```

---

## Build & Run

### Compile the Marketplace

```bash
g++ -std=c++17 -Iinclude src/OnlineMarketplace.cpp src/Product.cpp src/ShoppingList.cpp src/User.cpp main.cpp -o main
```

### Run the Program

```bash
# Linux / macOS
./main

# Windows
./main.exe
```
