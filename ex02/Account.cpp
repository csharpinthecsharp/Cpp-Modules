#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    std::cout << "[19920104_091532] " << "index:"<< _accountIndex << 
        ";amount:" << initial_deposit << ";created" << std::endl;
    _nbAccounts++;
    _totalAmount+=initial_deposit;
}
Account::~Account( void )
{
    std::cout << "[19920104_091532] " << "index:"
    << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    int p_amount = _amount;
    _amount+=deposit;
    _totalAmount+=deposit;
    _nbDeposits+=1;
    _totalNbDeposits+=1;
    std::cout << "[19920104_091532] " << "index:"
    << _accountIndex << ";p_amount:" << p_amount << ";deposit:"
        << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount = _amount;
    if (_amount >= withdrawal) {
        _totalNbWithdrawals+=1;
        _nbWithdrawals+=1;
        _amount-=withdrawal;
        _totalAmount-=withdrawal;
        std::cout << "[19920104_091532] " << "index:"
            << _accountIndex << ";p_amount:" << p_amount 
                << ";withdrawal:"  << withdrawal << ";amount:" 
                    << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
    std::cout << "[19920104_091532] " << "index:"
        << _accountIndex << ";p_amount:" << p_amount
            << ";withdrawal:" << "refused" << std::endl;
    return false;
}

int		Account::checkAmount( void ) const
{
    return Account::getTotalAmount();
}

void	Account::displayStatus( void ) const
{
    // I need to replace 19920104_091532 by _displayTimestamp()
    std::cout << "[19920104_091532] " << "index:"
        << _accountIndex << ";amount:" << _amount << ";deposit:"
            << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
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

void Account::displayAccountsInfos( void )
{
    std::cout << "[19920104_091532] " << "accounts:" 
        << _nbAccounts << ";total:" << _totalAmount << ";deposit:" 
            << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void )
{

}
