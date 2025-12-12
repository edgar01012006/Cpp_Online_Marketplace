#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <string>

class Product {
    public:
        enum class Category { 
            CLOTHING,
            FURNITURE,
            ELECTRONICS
        };

    private:
        std::string m_name;
        double m_price;
        Category m_category;
        size_t m_id;
        static size_t m_nextId;

        std::string categoryToString(Category category) const;

    public:
        Product(const std::string& name, size_t price, Category category);

        void setName(const std::string& name);
        void setPrice(double price);
        void setCategory(Category category);

        std::string getName() const { return m_name; }
        double getPrice() const { return m_price; }
        Category getCategory() const { return m_category; }
        size_t getId() const { return m_id; };

        friend std::ostream& operator<<(std::ostream& ostr, const Product& src);

};

#endif