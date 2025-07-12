
#include "ScalarConverter.hpp"

// COPLIEN'S FORM
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src) { (void)src; return (*this); }
ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string &input)
{
	if (isChar(input))
		toChar(input);
	else if (isInt(input))
		toInt(input);
	else if (isFloat(input))
		toFloat(input);
	else if (isDouble(input))
		toDouble(input);
	else if (isOther(input))
		toOther(input);
	else
		std::cout <<  "Invalid input. Enter a char, int, float or double value."  << std::endl;
}

// CHAR //////////////////////////////////////////////////////////////////////////////
bool	ScalarConverter::isChar(const std::string &input)
{
	if (input.size() == 1)
		return (true);
	if (input.size() == 3)
		if (input[0] == '\'' && input[2] == '\'')
			return (true);
	return (false);
}

void	ScalarConverter::toChar(const std::string &input)
{
	char	c = input[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	if (input.size() == 3)
		if (input[0] == '\'' && input[2] == '\'')
			c = input[1];

	if (isprint(c))
		std::cout <<  "char:   \t'" << c << "'"  << std::endl;
	else
		std::cout <<  "char:   \t" << "non displayable"  << std::endl;
	std::cout <<  "int:    \t" << i  << std::endl;
	std::cout <<  "float:  \t" << std::fixed << std::setprecision(1) << f  << "f"  << std::endl;
	std::cout <<  "double: \t" << d << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////

// INT ////////////////////////////////////////////////////////////////////////////////
bool	ScalarConverter::isInt(const std::string &input)
{
	size_t	startIndex = 0;

	if (input.empty()) return (false);

	while (startIndex < input.size() && std::isspace(input[startIndex]))
		startIndex++;
	if (startIndex == input.size())
		return (false);
	if (input[startIndex] == '+' || input[startIndex] == '-')
		startIndex++;
	if (startIndex == input.size() || std::isdigit(input[startIndex]) == 0)
		return (false);
	for (size_t i = startIndex; i < input.size(); i++)
	{
		if (std::isdigit(input[i]) == 0)
			return (false);
	}

	try
	{
		long long int result = std::atoll(input.c_str());
		if (result < INT_MIN || result > INT_MAX)
			return (false);
	}
	catch (...) { return (false); }

	return (true);
}

void	ScalarConverter::toInt(const std::string &input)
{
	char	c;
	int		i = std::atoi(input.c_str());
	float	f;
	double	d;


	if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
	{
		c = static_cast<char>(i);
		if (isprint(c))
			std::cout <<  "char:   \t'" << c << "'"  << std::endl;
		else
			std::cout <<  "char:   \t" << "non displayable"  << std::endl;
	}
	else
		std::cout <<  "char:   \t" << "impossible"  << std::endl;
	std::cout <<  "int:    \t" << i   << std::endl;
	
	f = static_cast<float>(i);
	std::cout <<  "float:  \t" << std::fixed << std::setprecision(1) << f << "f"  << std::endl;
	d = static_cast<double>(i);
	std::cout <<  "double: \t" << d  << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////



// FLOAT //////////////////////////////////////////////////////////////////////////////
bool	ScalarConverter::isFloat(const std::string &input)
{
	if (input.empty()) return (false);


	bool	digitBeforeDecimal = false;
	bool	decimalFound = false;
	bool	digitAfterDecimal = false;
	size_t	i = 0;

	while (i < input.size() && std::isspace(input[i]))
		i++;
	if (i == input.size())
		return (false);
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.size())
		return (false);

	for (; i < input.size() && std::isdigit(input[i]); i++)
		digitBeforeDecimal = true;

	if (i < input.size() && input[i] == '.')
	{
		decimalFound = true;
		i++;
	}
	// Vérifie les chiffres après le point
	for (; i < input.size() && std::isdigit(input[i]); i++)
		digitAfterDecimal = true;
	// Finir par 'f' ou 'F' après les chiffres
	if (i == input.size() - 1 && (input[i] == 'f' || input[i] == 'F')
		&& (digitBeforeDecimal || digitAfterDecimal) && decimalFound)
		return (true);

	return (false);
}

void	ScalarConverter::toFloat(const std::string &input)
{
	char	c;
	int		i;
	float	f = atof(input.c_str());
	double	d;

	if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
	{
		c = static_cast<char>(f);
		if (isprint(c))
			std::cout <<  "char:   \t'" << c << "'"  << std::endl;
		else
			std::cout <<  "char:   \t" << "non displayable"  << std::endl;
	}
	else
		std::cout <<  "char:   \t" << "impossible"  << std::endl;
	
	if (f >= static_cast<float>(std::numeric_limits<int>::min()) &&
		f <= static_cast<float>(std::numeric_limits<int>::max()))
	{
		i = static_cast<int>(f);
		std::cout <<  "int:    \t" << i   << std::endl;
	}
	else
		std::cout <<  "int:    \t" << "impossible"  << std::endl;
	
	std::cout <<  "float:  \t" << std::fixed << std::setprecision(1) << f << "f"  << std::endl;

	d = static_cast<double>(f);
	std::cout <<  "double: \t" << d   << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////

// DOUBLE /////////////////////////////////////////////////////////////////////////////
bool	ScalarConverter::isDouble(const std::string &input)
{
	if (input.empty()) return (false);

	size_t	i = 0;
	bool	digitBeforeDecimal = false;
	bool	decimalFound = false;
	bool	digitAfterDecimal = false;

	while (i < input.size() && std::isspace(input[i]))
		i++;
	if (i == input.size())
		return (false);
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.size())
		return (false);
	// Check chiffres avant le point
	for (; i < input.size() && std::isdigit(input[i]); i++)
		digitBeforeDecimal = true;
	// Check point décimal
	if (i < input.size() && input[i] == '.')
	{
		decimalFound = true;
		i++;
	}
	// Check chiffres après le point
	for (; i < input.size() && std::isdigit(input[i]); i++)
		digitAfterDecimal = true;

	if (i == input.size() && decimalFound && (digitBeforeDecimal || digitAfterDecimal))
		return (true);

	return (false);
}

void	ScalarConverter::toDouble(const std::string &input)
{
	char	c;
	int		i;
	float	f;
	double	d = std::atof(input.c_str());

	if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
	{
		c = static_cast<char>(d);
		if (isprint(c))
			std::cout <<  "char:   \t'" << c << "'"  << std::endl;
		else
			std::cout <<  "char:   \t" << "non displayable"  << std::endl;
	}
	else
		std::cout <<  "char:   \t" << "impossible"  << std::endl;
	
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
	{
		i = static_cast<int>(d);
		std::cout <<  "int:    \t" << i   << std::endl;
	}
	else
		std::cout <<  "int:    \t" << "impossible"  << std::endl;
	
	f = static_cast<float>(d);
	std::cout <<  "float:  \t" << std::fixed << std::setprecision(1) << f << "f"  << std::endl;

	std::cout <<  "double: \t" << d   << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////

// SPECIAL ////////////////////////////////////////////////////////////////////////////
bool	ScalarConverter::isOther(const std::string &input)
{
	const std::string	specials[] = { "-inff", "+inff", "nanf", "-inf", "+inf", "nan" };

	for (int i = 0; i < 6; i++)
	{
		if (input == specials[i])
			return (true);
	}
	return (false);
}

void	ScalarConverter::toOther(const std::string &input)
{
	std::cout <<  "char:   \t" << "impossible"  << std::endl;
	std::cout <<  "int:    \t" << "impossible"  << std::endl;

	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout <<  "float:  \t" << input   << std::endl;
		std::string inputFixed = input.substr(0, input.size() - 1);
		std::cout <<  "double: \t" << inputFixed  << std::endl;
	}
	else
	{
		std::cout <<   "float:  \t" << input << "f"  << std::endl;
		std::cout <<  "double: \t" << input   << std::endl;
	}
}
///////////////////////////////////////////////////////////////////////////////////////
