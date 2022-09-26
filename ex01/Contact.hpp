#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{

	public:

	Contact(void);
	~Contact(void);

	std::string	first;
	std::string	last;
	std::string	nick;
	std::string	nb;
	std::string	secret;

	private:

};

#endif
