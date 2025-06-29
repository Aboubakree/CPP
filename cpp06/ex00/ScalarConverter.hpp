#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
    enum Type {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        INVALID
    };

    static Type detectType(const std::string& literal);
    static void convertFromChar(char c);
    static void convertFromInt(int value);
    static void convertFromFloat(float value);
    static void convertFromDouble(double value);
    static bool isDisplayable(char c);

public:
    static void convert(const std::string& literal);
    
    // Make constructor private to prevent instantiation
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
};

#endif