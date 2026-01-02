#include "Product.hpp"

size_t Product::m_nextId = 0;

std::string Product::categoryToString(Category category) const {
    switch(category) {
        case Category::CLOTHING : return "Clothing";
        case Category::ELECTRONICS : return "Electronics";
        case Category::FURNITURE: return "Furniture";
        default: break;
    }
    return "None";
}

Product::Product(const std::string& name, double price, Category category) {
    try {
        setName(name);
        setPrice(price);
    } catch (const OnlineMarketplaceExceptions& ex) {
        std::cout << ex.what() << std::endl;
        return;
    }
    setCategory(category);
    m_id = ++m_nextId;
}

void Product::setName(const std::string& name) {
    if (name.length() > 30) {
        throw InvalidName("Invalid Name; max length 30 characters");
    }
    m_name = name;
}

void Product::setPrice(double price) {
    if (price < 0 || price > 500'000) {
        throw InvalidPrice("Invalid Price; 0 to 500'000 range");
    }
    m_price = price; 
}

void Product::setCategory(Category category) {
    m_category = category;
}

std::ostream& operator<<(std::ostream& ostr, const Product& src) {
    ostr << "Name: " << src.m_name << "\n"
         << "Price: " << src.m_price << "\n"
         << "Category: " << src.categoryToString(src.m_category) << "\n"
         << "Id: " << src.m_id << "\n";
    return ostr;
}