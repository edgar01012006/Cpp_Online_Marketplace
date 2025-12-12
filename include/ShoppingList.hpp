#ifndef SHOPPINGLIST_HPP
#define SHOPPINGLIST_HPP

#include <vector>
#include <memory>
#include "Product.hpp"
#include "OnlineMarketplace.hpp"
#include "User.hpp"

struct QuantityProduct {
    int m_count;
    std::weak_ptr<Product> m_product;
};

class ShoppingList {
    private:
        // SL = shopping list
        std::vector<std::unique_ptr<QuantityProduct>> m_SL; // the quantity of a product is different for every user
                                                            // hence we needed to aggregate it into a struct of QuanitiyProduct
                                                            // and QuanitityProduct is unique for every user

    public:
        void addProductToSL(OnlineMarketplace& om, size_t productId); // dependency with OnlineMarketplace
        void removeProductFromSL(size_t productId);

        double getTotalPriceOfSL() const;
        void displaySL() const;

        void purchaseSL(User& user); // dependency with User
        void cleanSL();

        //friend std::ostream& operator<<(std::ostream& ostr, const ShoppingList& src);

};

#endif