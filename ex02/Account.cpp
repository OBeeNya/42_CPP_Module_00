#include <iostream>
#include <ctime>
#include "Account.hpp"

Account::Account(void)
{
	Account::_nbAccounts++;

	Account::_accountIndex = Account::_nbAccounts - 1;
	Account::_amount = 0;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:0;created" \
	<< std::endl;

	return ;
}

Account::Account(int deposit)
{
	Account::_nbAccounts++;
	Account::_totalAmount += deposit;

	Account::_accountIndex = Account::_nbAccounts - 1;
	Account::_amount = deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:" << deposit \
	<< ";created" << std::endl;

	return ;
}

Account::~Account(void)
{
	Account::_nbAccounts--;

	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:" << \
	Account::_amount << ";closed" << std::endl;

	return ;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	time_t	now;
	tm		*gmtm;

	now = time(0);
	gmtm = gmtime(&now);
	std::cout << "[";
	std::cout << gmtm->tm_year;
	std::cout << gmtm->tm_mon;
	std::cout << gmtm->tm_mday;
	std::cout << "_";
	std::cout << gmtm->tm_hour;
	std::cout << gmtm->tm_min;
	std::cout << gmtm->tm_sec;
	std::cout << "] ";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << \
	Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() \
	<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" \
	<< this->_amount << ";deposit:" << deposit << ";amount:";
	
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	this->_amount += deposit;
	this->_nbDeposits++;

	std::cout << this->_amount << ";nb_deposits:" << this->_nbDeposits \
	<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" \
	<< this->_amount << ";withdrawal:";

	if (withdrawal <= this->_amount)
	{
		std::cout << withdrawal << ";amount:";

		this->_totalAmount -= withdrawal;
		this->_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;

		std::cout << this->_amount << ";nb_withdrawals:" \
		<< this->_nbWithdrawals << std::endl;

		return (true);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount \
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" \
	<< this->_nbWithdrawals << std::endl;
}
