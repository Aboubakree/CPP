#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdlib>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

class	ScalarConverter
{
	public:
		// MAIN MEMBER
		static void	convert(const std::string &input);

	private:
		// COPLIEN'S FORM (NOT INSTANCIABLE)
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter& operator=(const ScalarConverter &src);
		~ScalarConverter();

		// GUESS WHO'S BACK
		static bool	isChar(const std::string &input);
		static bool	isInt(const std::string &input);
		static bool	isFloat(const std::string &input);
		static bool	isDouble(const std::string &input);
		static bool	isOther(const std::string &input);
		// HERE YOU GO
		static void	toChar(const std::string &input);
		static void	toInt(const std::string &input);
		static void	toFloat(const std::string &input);
		static void	toDouble(const std::string &input);
		static void	toOther(const std::string &input);
};
