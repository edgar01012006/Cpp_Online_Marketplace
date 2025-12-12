#include "../include/OnlineMarketplace.hpp"
#include "../include/CustomExceptions.hpp"

void OnlineMarketplace::addProductToMarketplace(const std::string& name, size_t price, Product::Category category) {
    m_products.emplace_back(new Product {name, price, category} );
}

void OnlineMarketplace::removeProductFromMarketplace(size_t productId) {
    for (int i = 0; i < m_products.size(); ++i) {
        if (m_products[i]->getId() == productId) {
            m_products.erase(m_products.begin() + i);
            return;
        }
    }
    throw ProductIdNotFound("Product Id not found");
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