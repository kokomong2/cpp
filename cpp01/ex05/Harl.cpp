#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl is dead, long live Harl!" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl is dead, long live Harl!" << std::endl;
}

void	Harl::complain(std::string level)
{
	if (level == "debug")
		this->debug();
	else if (level == "info")
		this->info();
	else if (level == "warning")
		this->warning();
	else if (level == "error")
		this->error();
	else
		std::cout << "Invalid level" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "Debug" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Info" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Warning" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "Error" << std::endl;
}
