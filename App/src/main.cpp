#include "../include/SystemApp.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        // You can change "Guest" to any name you like!
        SystemApp app("Edgar");
        
        std::cout << "Starting System..." << std::endl;
        
        // This enters the Master Menu loop
        app.run();
        
    } catch (const std::exception& e) {
        // This catches any critical system errors that weren't 
        // caught by your internal menus.
        std::cerr << "\nCRITICAL SYSTEM ERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}