#include <iostream>
#include <iomanip>
#include "include/Product.hpp"
#include "include/OnlineMarketplace.hpp"
#include "include/ShoppingList.hpp"
#include "include/User.hpp"
#include "include/CustomExceptions.hpp"

int main() {
    std::cout << std::fixed << std::setprecision(2);

    try {
        std::cout << "=== SETUP: Marketplace & Products ===\n";
        OnlineMarketplace marketplace;

        // Add Products (IDs will start at 1,2,3,... given your Product implementation)
        marketplace.addProductToMarketplace("T-Shirt", 25, Product::Category::CLOTHING);       // id = 1
        marketplace.addProductToMarketplace("Laptop", 1200, Product::Category::ELECTRONICS);  // id = 2
        marketplace.addProductToMarketplace("Sofa", 800, Product::Category::FURNITURE);       // id = 3
        marketplace.addProductToMarketplace("Jeans", 45, Product::Category::CLOTHING);       // id = 4

        std::cout << "\nAll Products in Marketplace:\n";
        marketplace.displayAllProducts();

        std::cout << "\nProducts in ELECTRONICS category:\n";
        marketplace.displayCategory(Product::Category::ELECTRONICS);

        std::cout << "\n=== SETUP: Users ===\n";
        User alice("Alice");
        User bob("Bob");
        User charlie("Charlie");

        // Deposits
        std::cout << "Depositing money to users...\n";
        alice.deposit(3000.0);   // make Alice able to complete her big SL
        bob.deposit(900.0);      // Bob will be able to buy his small SL
        charlie.deposit(100.0);  // Charlie intentionally underfunded for a test

        std::cout << "Balances:\n";
        std::cout << " - " << alice.getName() << ": " << alice.getBalance() << "\n";
        std::cout << " - " << bob.getName()   << ": " << bob.getBalance()   << "\n";
        std::cout << " - " << charlie.getName() << ": " << charlie.getBalance() << "\n";

        std::cout << "\n=== SHOPPING LISTS: Add items & quantities ===\n";
        ShoppingList slAlice;
        ShoppingList slBob;
        ShoppingList slCharlie;

        // Alice: wants 1 T-Shirt and 2 Laptops => total = 25 + 1200*2 = 2425
        slAlice.addProductToSL(marketplace, 1); // T-Shirt
        slAlice.addProductToSL(marketplace, 2); // Laptop
        slAlice.addProductToSL(marketplace, 2); // Laptop again -> quantity++ for product id 2

        // Bob: wants Sofa + Jeans => total = 800 + 45 = 845
        slBob.addProductToSL(marketplace, 3); // Sofa
        slBob.addProductToSL(marketplace, 4); // Jeans

        // Charlie: wants one Laptop -> total = 1200 (but he only has 100)
        slCharlie.addProductToSL(marketplace, 2); // Laptop

        std::cout << "\nAlice's Shopping List:\n";
        slAlice.displaySL();
        std::cout << "Alice SL total: " << slAlice.getTotalPriceOfSL() << "\n";

        std::cout << "\nBob's Shopping List:\n";
        slBob.displaySL();
        std::cout << "Bob SL total: " << slBob.getTotalPriceOfSL() << "\n";

        std::cout << "\nCharlie's Shopping List:\n";
        slCharlie.displaySL();
        std::cout << "Charlie SL total: " << slCharlie.getTotalPriceOfSL() << "\n";

        std::cout << "\n=== PURCHASE ATTEMPTS ===\n";

        // Alice attempt (should succeed because we deposited 3000)
        std::cout << "\nAlice attempts purchase:\n";
        try {
            slAlice.purchaseSL(alice);
            std::cout << "Alice purchase succeeded. New balance: " << alice.getBalance() << "\n";
        } catch (const OnlineMarketplaceExceptions& ex) {
            std::cout << "Alice purchase failed with exception: " << ex.what() << "\n";
        }

        // Bob attempt (should succeed with 900 balance)
        std::cout << "\nBob attempts purchase:\n";
        try {
            slBob.purchaseSL(bob);
            std::cout << "Bob purchase succeeded. New balance: " << bob.getBalance() << "\n";
        } catch (const OnlineMarketplaceExceptions& ex) {
            std::cout << "Bob purchase failed with exception: " << ex.what() << "\n";
        }

        // Charlie attempt (should fail: insufficient funds)
        std::cout << "\nCharlie attempts purchase (expected to fail):\n";
        try {
            slCharlie.purchaseSL(charlie);
            std::cout << "Charlie purchase succeeded unexpectedly. New balance: " << charlie.getBalance() << "\n";
        } catch (const OnlineMarketplaceExceptions& ex) {
            std::cout << "Charlie purchase failed as expected: " << ex.what() << "\n";
        }

        std::cout << "\n=== FURTHER OPERATIONS ===\n";

        // Test removing a product from marketplace then trying to add it to a shopping list
        std::cout << "\nRemoving product ID 1 (T-Shirt) from marketplace...\n";
        try {
            marketplace.removeProductFromMarketplace(1);
            std::cout << "Removed product id 1.\n";
        } catch (const OnlineMarketplaceExceptions& ex) {
            std::cout << "Failed to remove product id 1: " << ex.what() << "\n";
        }

        std::cout << "\nCurrent products after removal:\n";
        marketplace.displayAllProducts();

        // Attempt to add removed product to a new shopping list (should throw ProductIdNotFound)
        std::cout << "\nAttempting to add removed product ID 1 to a shopping list (expected to fail):\n";
        try {
            ShoppingList tmpSL;
            tmpSL.addProductToSL(marketplace, 1); // product 1 was removed
            std::cout << "Unexpected: able to add removed product to shopping list.\n";
        } catch (const OnlineMarketplaceExceptions& ex) {
            std::cout << "Adding removed product failed as expected: " << ex.what() << "\n";
        }

        // Test negative deposit / withdraw exceptions
        std::cout << "\nTesting negative deposit/withdraw exceptions (expected to throw NegativeAmount):\n";
        try {
            alice.deposit(-50.0);
            std::cout << "Unexpected: negative deposit did not throw.\n";
        } catch (const OnlineMarketplaceExceptions& ex) {
            std::cout << "Negative deposit threw as expected: " << ex.what() << "\n";
        }

        try {
            bob.withdraw(-10.0);
            std::cout << "Unexpected: negative withdraw did not throw.\n";
        } catch (const OnlineMarketplaceExceptions& ex) {
            std::cout << "Negative withdraw threw as expected: " << ex.what() << "\n";
        }

        // Test withdraw more than balance (InsufficientFunds)
        std::cout << "\nTesting withdraw more than balance (expected InsufficientFunds):\n";
        try {
            bob.withdraw(10000.0);
            std::cout << "Unexpected: over-withdraw did not throw.\n";
        } catch (const OnlineMarketplaceExceptions& ex) {
            std::cout << "Over-withdraw threw as expected: " << ex.what() << "\n";
        }

        // test findProductById success and failure printing
        std::cout << "\nTesting findProductById:\n";
        try {
            const std::shared_ptr<Product>& p = marketplace.findProductById(2);
            std::cout << "Found product id 2:\n" << *p << "\n";
        } catch (const OnlineMarketplaceExceptions& ex) {
            std::cout << "Finding product id 2 failed: " << ex.what() << "\n";
        }

        try {
            const std::shared_ptr<Product>& p = marketplace.findProductById(999); // expect failure
            std::cout << "Unexpected: found product id 999:\n" << *p << "\n";
        } catch (const OnlineMarketplaceExceptions& ex) {
            std::cout << "Finding product id 999 failed as expected: " << ex.what() << "\n";
        }

        std::cout << "\n=== FINAL STATE ===\n";
        std::cout << "Marketplace products:\n";
        marketplace.displayAllProducts();

        std::cout << "\nEnd of tests.\n";

    } catch (const OnlineMarketplaceExceptions& ex) {
        // top-level unexpected exceptions from your types
        std::cout << "Top-level exception: " << ex.what() << "\n";
    } catch (...) {
        std::cout << "Top-level unknown exception occurred.\n";
    }

    return 0;
}
