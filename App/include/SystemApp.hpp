#ifndef SYSTEM_APP_HPP
#define SYSTEM_APP_HPP

#include <string>

#include "Bank.hpp"
#include "OnlineMarketplace.hpp"
#include "User.hpp"

class SystemApp {
    private:
        Bank m_bank;
        OnlineMarketplace m_marketplace;
        User m_user;

        // Internal helper to keep the run() loop clean
        void displayMasterMenu() const;

    public:
        // Constructor initializes the default user of the application
        explicit SystemApp(const std::string& userName);

        // The main entry point that starts the menu loops
        void run();
};

#endif