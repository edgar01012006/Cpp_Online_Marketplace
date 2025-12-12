#include "../include/ShoppingList.hpp"
#include "../include/CustomExceptions.hpp"

void ShoppingList::addProductToSL(OnlineMarketplace& om, size_t productId) {
    for (int i = 0; i < m_SL.size(); ++i) { // search if product exists in shopping list
        if (auto tmpProduct = m_SL[i]->m_product.lock()) {
            if (tmpProduct->getId() == productId) {
                ++m_SL[i]->m_count;
                return;
            }
        }
    }   
    try {
        const std::shared_ptr<Product>& product = om.findProductById(productId);
        m_SL.emplace_back(new QuantityProduct { 1, product }); // add a new product into shopping list
        return;
    } catch (const OnlineMarketplaceExceptions& ex) {
        std::cout << ex.what() << std::endl;
        return;
    }
    throw ProductIdNotFound("Product Id not found");
}

void ShoppingList::removeProductFromSL(size_t productId) {
    for (int i = 0; i < m_SL.size(); ++i) {
        if (auto tmpProduct = m_SL[i]->m_product.lock()) {
            if (tmpProduct->getId() == productId) {
                m_SL.erase(m_SL.begin() + i);   
            }
        }
    }
    throw ProductIdNotFound("Product Id not found");   
}

double ShoppingList::getTotalPriceOfSL() const {
    double totalPrice = 0.0;
    for (int i = 0; i < m_SL.size(); ++i) {
        if (auto tmpProduct = m_SL[i]->m_product.lock()) {
            totalPrice += m_SL[i]->m_count * tmpProduct->getPrice();
        }
    }
    return totalPrice;
}

void ShoppingList::displaySL() const {
    for (int i = 0; i < m_SL.size(); ++i) {
        if (auto tmpProduct = m_SL[i]->m_product.lock()) {
            std::cout << *tmpProduct;
            std::cout << "Quantity: " << m_SL[i]->m_count << "\n";
        }
    }
}

void ShoppingList::purchaseSL(User& user) {
    // in future we can add a bank account for our OnlineMarketplace
    // where we will pass the amount to our bank account(OnlineMarketPlace)
    double totalPriceSL = getTotalPriceOfSL();
    if (totalPriceSL > user.getBalance()) {
        throw InsufficientFunds("Insufficient funds");
    }
    user.withdraw(totalPriceSL);
    cleanSL();
}

void ShoppingList::cleanSL() {
    m_SL.clear();
}