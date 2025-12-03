#include "Account.hpp"

Account::Account( int initial_deposit )
{
    Account::_totalNbDeposits = initial_deposit;
}
Account::~Account( void )
{
    
}

void	Account::makeDeposit( int deposit )
{
    _totalAmount += deposit;
    _totalNbDeposits+=1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    return true;
}

int		Account::checkAmount( void ) const
{
    return Account::getTotalAmount();
}

void	Account::displayStatus( void ) const
{

}

int Account::getNbAccounts( void )
{
    return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
    return _totalAmount;
}
int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}