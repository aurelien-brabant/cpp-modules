#include <string>
#include <iostream>
#include "Account.hpp"

void	Account::makeDeposit(int deposit) {

	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		<< ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << ++_nbDeposits << std::endl;
	_amount += deposit;
	_totalNbDeposits++; 
	_totalAmount += deposit;
};

bool Account::makeWithdrawal(int withdrawal)
{
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal <= _amount) {
		std::cout << withdrawal << ";amount:" << _amount - withdrawal
			<< ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	} else {
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	return true;
}

int		Account::checkAmount( void ) const { return _amount; };

void Account::displayStatus(void) const
{
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// constructor

Account::Account( int initial_deposit ): _accountIndex(_nbAccounts++), _amount(initial_deposit)
{
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl; 
	_totalAmount += _amount;
}

Account::~Account(void)
{
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl; 
};

// static members definition

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalAmount = 0;

int	Account::getNbAccounts( void ) { return _nbAccounts; };

int	Account::getTotalAmount( void ) { return _totalAmount; };

int	Account::getNbDeposits( void ) { return _totalNbDeposits; };

int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; };

void Account::displayAccountsInfos( void )
{
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" 
		<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

