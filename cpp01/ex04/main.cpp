#include "main.hpp"

int main(int ac, char **argv)
{
    std::stringstream    buffer;
    std::string          infile_content;
    size_t               start = 0;
	size_t               s1_length;
	size_t               file_length;

    if (ac != 4)
        return std::cerr << "Bad argumment : ./replace filename string1 string2" << std::endl, 1;
    std::ifstream infile(argv[1], std::ios::in);
    if (infile.fail())
        return std::cerr << "can't open " << argv[1] << std::endl, 1;
    std::ofstream outfile(((std::string)argv[1] + ".replace").c_str(), std::ios::out);
    if (outfile.fail())
        return std::cerr << "can't open " << (std::string)argv[1] + ".replace" << std::endl, 1;
    buffer << infile.rdbuf();
    infile_content = buffer.str();
    s1_length = ((std::string)argv[2]).length();
	file_length = infile_content.length();
    if (argv[2][0] == '\0')
	return outfile.write(infile_content.c_str(), file_length), 0;
    while (start < file_length)
    {
		if (infile_content.substr(start, s1_length) == (std::string)argv[2])
		{
			outfile.write(argv[3], strlen(argv[3]));
			start += s1_length;
	}
		else
		{
			outfile.write(&(infile_content.c_str())[start] , 1);
			start ++;
		}
    }
    infile.close();
    outfile.close();
}
