#ifndef CART_HPP
#define CART_HPP

#include <vector>
#include <memory>
#include "Product.hpp"
#include "OnlineMarketplace.hpp"
#include "User.hpp"
#include "OnlineMarketplaceExceptions.hpp"

struct QuantityProduct {
    int m_count;
    std::weak_ptr<Product> m_product;
};

class Cart {
    private:
        std::vector<std::unique_ptr<QuantityProduct>> m_cart; // the quantity of a product is different for every user
                                                              // hence we needed to aggregate it into a struct of QuanitiyProduct
                                                              // and QuanitityProduct is unique for every user

    public:
        void addProductToCart(OnlineMarketplace& om, size_t productId); // dependency with OnlineMarketplace
        void removeProductFromCart(size_t productId);

        double getTotalPriceOfCart() const;
        void displayCart() const;

        void purchaseCart();
        void cleanCart();

        // friend std::ostream& operator<<(std::ostream& ostr, const ShoppingList& src);

};

#endif