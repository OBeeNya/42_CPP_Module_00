#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <limits>
# include "Contact.hpp"

class	PhoneBook
{

	public:

	PhoneBook(void);
	~PhoneBook(void);

	void	ft_add_contact(void);
	void	ft_search_contact(void) const;

	private:

	Contact	_contacts[8];
	int		_old;
	int		_many;

};

#endif
