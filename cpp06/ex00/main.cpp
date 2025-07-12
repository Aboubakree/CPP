#include "ScalarConverter.hpp"









int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: ./convert <value_to_cast> " << std::endl;
		return 1;
	}
	std::cout <<   "user input:\t\"" << argv[1] << "\""  << std::endl;
	
	if (argv[1][0])
		ScalarConverter::convert(argv[1]);
	else
		std::cout <<  "Argument is empty."  << std::endl;
	return (0);
}
