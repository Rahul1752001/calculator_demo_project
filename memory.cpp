#include "memory.h"
#include <iostream>

// Placeholder memory implementation using a static variable
namespace Memory {
    double storedValue = 0.0;
    
    void store(double value) {
        storedValue = value;
        std::cout << "Value " << value << " stored in memory" << std::endl;
    }
    
    double recall() {
        std::cout << "Value " << storedValue << " recalled from memory" << std::endl;
        return storedValue;
    }
    
    void clear() {
        storedValue = 0.0;
        std::cout << "Memory cleared" << std::endl;
    }
}
