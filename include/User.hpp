#ifndef USER_HPP
#define USER_HPP

#include <string>

class User {
    private:
        std::string m_name;
        double m_balance;
        size_t m_id;
        static size_t m_nextId;
        

    public:
        User(const std::string& name);
        void deposit(double amount);
        void withdraw(double amount);
        
        size_t getId() const { return m_id; }
        std::string getName() const { return m_name; }
        double getBalance() const { return m_balance; }
        
};

#endif