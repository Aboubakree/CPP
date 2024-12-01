#include <iostream>
#include <cmath> // For rounding

class FixedPoint {
private:
    int _value;                          // Scaled integer value
    static const int _fractionalBits = 8; // Number of fractional bits (8 bits)

public:
    // Default constructor
    FixedPoint() : _value(0) {}

    // Constructor from a float
    FixedPoint(float number) {
        _value = (int)(roundf(number * (1 << _fractionalBits)));
    }

    // Constructor from an integer
    FixedPoint(int number) {
        _value = number << _fractionalBits;
    }

    // Get the raw integer value
    int getRawBits() const {
        return _value;
    }

    // Convert back to float
    float toFloat() const {
        return (float)(_value) / (1 << _fractionalBits);
    }

    // Addition operator
    FixedPoint operator+(const FixedPoint& other) const {
        FixedPoint result;
        result._value = this->_value + other._value;
        return result;
    }

    // Subtraction operator
    FixedPoint operator-(const FixedPoint& other) const {
        FixedPoint result;
        result._value = this->_value - other._value;
        return result;
    }

    // Print the fixed-point value as float
    void print() const {
        std::cout << "FixedPoint value (float): " << toFloat() << std::endl;
    }
};

int main() {

    float x = 0.1234567f;
    std::cout << x << std::endl;
    // FixedPoint a(5.75f); // Initialize with a float
    // FixedPoint b(2);     // Initialize with an integer
    // FixedPoint c;

    // std::cout << "Raw value of a: " << a.getRawBits() << std::endl;
    // std::cout << "Raw value of b: " << b.getRawBits() << std::endl;

    // a.print();
    // b.print();

    // c = a + b; // Add two fixed-point numbers
    // c.print();

    return 0;
}
