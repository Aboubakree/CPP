#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <climits>

ScalarConverter::ScalarConverter() 
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{ 
    (void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{ 
    (void)other; 
    return *this; 
}

ScalarConverter::~ScalarConverter() 
{}

bool ScalarConverter::isDisplayable(char c)
{
    return (c >= 32 && c <= 126);
}

ScalarConverter::Type ScalarConverter::detectType(const std::string& literal)
{
    if (literal.empty())
        return INVALID;

    // Check for char type: 'c'
    // if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    //     return CHAR;
    if (literal.length() == 1 && std::isalpha(static_cast<unsigned char>(literal[0])))
    {
        return CHAR;
    }

    // Check for special float values
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return FLOAT;

    // Check for special double values
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return DOUBLE;

    // Check for float type (ends with 'f')
    if (literal.length() > 1 && literal[literal.length() - 1] == 'f')
    {
        std::string temp = literal.substr(0, literal.length() - 1);
        if (temp.find('.') != std::string::npos)
            return FLOAT;
    }

    // Check for double type (contains decimal point)
    if (literal.find('.') != std::string::npos)
        return DOUBLE;

    // Check for int type (only digits and optional sign)
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-')
        start = 1;
    
    for (size_t i = start; i < literal.length(); i++)
    {
        if (std::isdigit(literal[i]) == 0)
            return INVALID;
    }
    
    return INT;
}

void ScalarConverter::convertFromChar(char c)
{
    std::cout << "char: ";
    if (isDisplayable(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromInt(int value)
{
    std::cout << "char: ";
    if (value < CHAR_MIN || value > CHAR_MAX)
        std::cout << "impossible" << std::endl;
    else if (isDisplayable(static_cast<char>(value)))
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromFloat(float value)
{
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < CHAR_MIN || value > CHAR_MAX)
        std::cout << "impossible" << std::endl;
    else if (isDisplayable(static_cast<char>(value)))
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value < (float)INT_MIN || value > (float)INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inff" : "+inff") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;

    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromDouble(double value)
{
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < CHAR_MIN || value > CHAR_MAX)
        std::cout << "impossible" << std::endl;
    else if (isDisplayable(static_cast<char>(value)))
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inff" : "+inff") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;

    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    Type type = detectType(literal);

    switch (type)
    {
        case CHAR:
            convertFromChar(literal[1]);
            break;
        
        case INT:
        {
            long long temp = std::atoll(literal.c_str());
            if (temp < INT_MIN || temp > INT_MAX)
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
            }
            else
                convertFromInt(static_cast<int>(temp));
            break;
        }
        
        case FLOAT:
        {
            float value;
            if (literal == "nanf")
                value = std::numeric_limits<float>::quiet_NaN();
            else if (literal == "+inff")
                value = std::numeric_limits<float>::infinity();
            else if (literal == "-inff")
                value = -std::numeric_limits<float>::infinity();
            else
                value = std::atof(literal.c_str());
            convertFromFloat(value);
            break;
        }
        
        case DOUBLE:
        {
            double value;
            if (literal == "nan")
                value = std::numeric_limits<double>::quiet_NaN();
            else if (literal == "+inf")
                value = std::numeric_limits<double>::infinity();
            else if (literal == "-inf")
                value = -std::numeric_limits<double>::infinity();
            else
                value = std::atof(literal.c_str());
            convertFromDouble(value);
            break;
        }
        
        default:
            std::cout << "Error: Invalid literal format" << std::endl;
            break;
    }
}