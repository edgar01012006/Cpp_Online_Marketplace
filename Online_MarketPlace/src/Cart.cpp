#include "../include/Cart.hpp"
#include "../include/OnlineMarketplace.hpp"

void Cart::addProductToCart(OnlineMarketplace& om, size_t productId) {
    for (int i = 0; i < m_cart.size(); ++i) { // search if product exists in shopping list
        if (auto tmpProduct = m_cart[i]->m_product.lock()) {
            if (tmpProduct->getId() == productId) {
                ++m_cart[i]->m_count;
                return;
            }
        }
    }   
    try {
        const std::shared_ptr<Product>& product = om.findProductById(productId);
        m_cart.emplace_back(std::make_unique<QuantityProduct>(1, product)); // add a new product into shopping list
                                                                            // C++20 added support for aggregate initialization through make_unique and make_shared
        return;
    } catch (const OnlineMarketplaceExceptions& ex) {
        throw; // rethrow so that user decided what to do with it.
    }
}

void Cart::removeProductFromCart(size_t productId) {
    for (int i = 0; i < m_cart.size(); ++i) {
        if (auto tmpProduct = m_cart[i]->m_product.lock()) {
            if (tmpProduct->getId() == productId) {
                m_cart.erase(m_cart.begin() + i);   
                return;
            }
        }
    }
    throw ProductIdNotFound("Product Id not found");   
}

double Cart::getTotalPriceOfCart() const {
    double totalPrice = 0.0;
    for (int i = 0; i < m_cart.size(); ++i) {
        if (auto tmpProduct = m_cart[i]->m_product.lock()) {
            totalPrice += m_cart[i]->m_count * tmpProduct->getPrice();
        }
    }
    return totalPrice;
}

void Cart::displayCart() const {
    for (int i = 0; i < m_cart.size(); ++i) {
        if (auto tmpProduct = m_cart[i]->m_product.lock()) {
            std::cout << *tmpProduct;
            std::cout << "Quantity: " << m_cart[i]->m_count << "\n";
        }
    }
}

void Cart::cleanCart() {
    m_cart.clear();
}