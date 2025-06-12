#include <iostream>
#include <stdexcept>

class Resource {
private:
    std::string name;
    int* data;

public:
    Resource(const std::string& n) : name(n), data(new int[100]) {
        std::cout << "🔧 Resource '" << name << "' constructed (allocated 400 bytes)" << std::endl;
    }
    
    ~Resource() {
        delete[] data;
        std::cout << "🗑️  Resource '" << name << "' destroyed (freed 400 bytes)" << std::endl;
    }
    
    void doWork() {
        std::cout << "⚙️  Resource '" << name << "' doing work..." << std::endl;
    }
};

void level3Function() {
    std::cout << "\n📍 Entering level3Function()" << std::endl;
    Resource res3("Level3Resource");
    res3.doWork();
    
    std::cout << "💥 About to throw exception in level3Function()" << std::endl;
    throw std::runtime_error("Something went wrong in level3!");
    
    // This line never executes
    std::cout << "❌ This line never executes" << std::endl;
}

void level2Function() {
    std::cout << "\n📍 Entering level2Function()" << std::endl;
    Resource res2("Level2Resource");
    res2.doWork();
    
    try {
        level3Function();
    } catch (const std::runtime_error& e) {
        std::cout << "🚫 Caught in level2: " << e.what() << std::endl;
        std::cout << "🔄 Re-throwing exception..." << std::endl;
        throw; // Re-throw the same exception
    }
    
    std::cout << "📤 Exiting level2Function()" << std::endl;
}

void level1Function() {
    std::cout << "\n📍 Entering level1Function()" << std::endl;
    Resource res1("Level1Resource");
    res1.doWork();
    
    level2Function();
    
    std::cout << "📤 Exiting level1Function()" << std::endl;
}

int main() {
    std::cout << "=== Stack Unwinding Demonstration ===" << std::endl;
    std::cout << "📚 Watch how destructors are called during unwinding" << std::endl;
    
    try {
        level1Function();
    } catch (const std::exception& e) {
        std::cout << "\n🎯 Final catch in main(): " << e.what() << std::endl;
    }
    
    std::cout << "\n✅ Program continues after exception handling" << std::endl;
    return 0;
}