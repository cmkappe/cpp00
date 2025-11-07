/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:47:16 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/11/07 16:25:14 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "./Account.hpp"
	#include <iostream>
	
	int Account::_nbAccounts = 0;
	int Account::_totalAmount = 0;
	int Account::_totalNbDeposits = 0;
	int Account::_totalNbWithdrawals = 0;

		
	void Account::_displayTimestamp() {
	time_t now = time(NULL);
	struct tm *timeinfo = localtime(&now);
	char buffer[20];

	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << buffer;
	}
		
	


	Account::Account( int initial_deposit ) : 
	_amount(initial_deposit), _accountIndex(_nbAccounts){
		_totalAmount += initial_deposit;
		_nbAccounts++;
		
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount 
			<< ";created"
			<< std::endl; 
	 };
	
	Account::~Account( void ) {
		_displayTimestamp();		
		std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount 
			<< ";closed"
			<< std::endl; 
	}

	int	Account::getNbAccounts( void ) {
		return _nbAccounts;
	}
	
	int	Account::getTotalAmount( void ){
		return _totalAmount;
	}
	
	int	Account::getNbDeposits( void ){
		return _totalNbDeposits;
	}
	
	int	Account::getNbWithdrawals( void ){
		return _totalNbWithdrawals;
	}
	
	void	Account::displayAccountsInfos( void ){
		_displayTimestamp();
		std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:"
			<< _totalNbDeposits << ";withdrawal:" << _totalNbWithdrawals << std::endl;
	}


	void	Account::displayStatus( void ) const{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount 
			<< ";deposits:" << _nbDeposits 
			<< ";withdrawal:" << _nbWithdrawals 
			<< std::endl; 
	}


	void	Account::makeDeposit( int deposit ){
		//int	previousAmount = _amount;

		_amount += deposit;
		_nbDeposits++;
		_totalAmount += deposit;
		_totalNbDeposits++;	

		_displayTimestamp();
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount - deposit
			<< ";deposits:" << deposit 
			<< ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits 
			<< std::endl; 
			
	}
	
	bool	Account::makeWithdrawal (int withdrawal){
		
		_displayTimestamp();
		if (withdrawal > _amount){
			std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:" 
				<< "refused" 
				<< std::endl;
			return false;
		}
		else{
			_amount -= withdrawal;
			_totalAmount -= withdrawal;
			
			std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount - withdrawal
				<< ";withdrawal:" << withdrawal 
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals 
				<< std::endl;
			
			return true;
		}
	}

	
	int		Account::checkAmount( void ) const{
		return _amount;
	}



	


	