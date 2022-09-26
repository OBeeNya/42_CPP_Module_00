#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_many = 0;
	this->_old = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::ft_add_contact(void)
{
	int	next;

	if (!this->_many)
		next = this->_many;
	else if (this->_many < 8)
		next = this->_many;
	else
	{
		if (this->_old != 7)
			next = this->_old + 1;
		else
			next = 0;
	}
	std::cout << "First name: ";
	std::cin >> this->_contacts[next].first;
	std::cout << "Last name: ";
	std::cin >> this->_contacts[next].last;
	std::cout << "Nickname: ";
	std::cin >> this->_contacts[next].nick;
	std::cout << "Phone number: ";
	std::cin >> this->_contacts[next].nb;
	std::cout << "Darkest secret: ";
	std::cin >> this->_contacts[next].secret;
	if (this->_many < 8)
		this->_many++;	
	if (this->_old != 7 && this->_many != 1)
		this->_old++;
	else
		this->_old = 0;
}

void	PhoneBook::ft_search_contact(void) const
{
	int	i;
	int	j;
	int	read;	

	i = -1;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	while (++i < this->_many)
	{
		std::cout << "|         " << i << "|";
		if (this->_contacts[i].first.length() > 10)
			std::cout << this->_contacts[i].first.substr(0, 9) + ".";
		else
		{
			j = 10 - this->_contacts[i].first.length();
			while (j--)
				std::cout << " ";
			std::cout << this->_contacts[i].first;
		}
		std::cout << "|";
		if (this->_contacts[i].last.length() > 10)
			std::cout << this->_contacts[i].last.substr(0, 9) + ".";
		else
		{
			j = 10 - this->_contacts[i].last.length();
			while (j--)
				std::cout << " ";
			std::cout << this->_contacts[i].last;
		}
		std::cout << "|";
		if (this->_contacts[i].nick.length() > 10)
			std::cout << this->_contacts[i].nick.substr(0, 9) + ".";
		else
		{
			j = 10 - this->_contacts[i].nick.length();
			while (j--)
				std::cout << " ";
			std::cout << this->_contacts[i].nick;
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "Which index would you like to read? ";
	std::cin >> read;
	if (!std::cin || read < 0 || read >= this->_many)
		std::cout << "Index invalid, quitting search..." << std::endl;
	else
	{
		std::cout << "First name: " << this->_contacts[read].first << std::endl;
		std::cout << "Last name: " << this->_contacts[read].last << std::endl;
		std::cout << "Nickname: " << this->_contacts[read].nick << std::endl;
		std::cout << "Phone number: " << this->_contacts[read].nb << std::endl;
		std::cout << "Darkest secret: " << this->_contacts[read].secret << std::endl;
	}
}
