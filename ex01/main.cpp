#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << "> ";
		std::cin.clear();
		std::cin >> cmd;
		if (!std::cin)
			continue ;
		if (!(cmd.compare("EXIT")))
			break ;
		if (!(cmd.compare("ADD")))
			phonebook.ft_add_contact();
		if (!(cmd.compare("SEARCH")))
			phonebook.ft_search_contact();
	}
	return (0);
}
