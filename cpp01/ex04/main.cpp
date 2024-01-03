#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	std::string		filename = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::string		line;
	std::ifstream	ifs(filename);
	std::ofstream	ofs(filename + ".replace");

	if (!ifs.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	if (!ofs.is_open())
	{
		std::cout << "Error: could not create file" << std::endl;
		return (1);
	}
	while (std::getline(ifs, line))
	{
		size_t pos = 0;
		while (true)
		{
			pos = line.find(s1, pos);
			if (pos == std::string::npos)
			{
				break ;
			}
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		ofs << line;
		if (ifs.eof())
			break ;
		ofs << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}