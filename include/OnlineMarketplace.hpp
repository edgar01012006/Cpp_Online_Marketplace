#ifndef ONLINEMARKETPLACE_HPP
#define ONLINEMARKETPLACE_HPP

#include <vector>
#include <memory>
#include "Product.hpp"

class OnlineMarketplace {
    private:
        std::vector<std::shared_ptr<Product>> m_products;

    public:
        void addProductToMarketplace(const std::string& name, size_t price, Product::Category category); // not noexcept because bad_alloc isn't handled
        void removeProductFromMarketplace(size_t productId);

        void displayAllProducts() const;
        void displayCategory(Product::Category category) const;
        //void displayProductShoppersCount(size_t productId) const;

        const std::shared_ptr<Product>& findProductById(size_t productId) const;
};

#endif