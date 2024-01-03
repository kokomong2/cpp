
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (int j = 0; j < static_cast<char>(str.length()); j++)
			{
				std::cout << static_cast<char>(std::toupper(str[j])) << std::endl;
			}
		}
	}
}
