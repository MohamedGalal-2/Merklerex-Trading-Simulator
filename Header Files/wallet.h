/*File Guard*/
#pragma once
#ifndef _WALLET_H_
#define _WALLET_H_

/*Includes Section*/
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include "..\Header Files\orderBookEntry.h"
#include "..\Header Files\CSVReader.h"
#include "..\Header Files\colors.h"


class wallet
{
public:
	wallet();
	/**
	  * @brief This function will insert currency into the wallet
	  * @param type - The type of the product
	  * @param amount - The amount of the product
	  * @return void
	  */
	void insrtIntoWallet(std::string type, double amount);

	/**
	  * @brief This function will remove currency from the wallet
	  * @param type - The type of the product
	  * @param amount - The amount of the product
	  * @return bool - True if the wallet has enough money, false if not
	  */
	bool removeFromWallet(std::string type, double amount);

	/**
	  * @brief This function will check if the wallet has enough money to buy/sell
	  * @param type - The type of the currency
	  * @param amount - The amount of the currency
	  * @return bool - True if the wallet has enough money, false if not
	  * @note If the wallet does not have enough money, it will print an error message
	  */
	bool checkWallet(std::string type, double amount);
	/**
	  * @brief This function will check if the wallet has enough money to ask or bid
	  * @param order - The order that the user wants to ask or bid
	  * @return bool - True if the wallet has enough money, false if not
	  */
	bool isEnough(orderBookEntry order);

	/**
	  * @brief This function generates a string representation of the wallet
	  * @return std::string - The string representation of the wallet
	  * @note The string representation of the wallet is in the format of:
	  */
	std::string toString();

private:
	std::map<std::string, double> currencies;
};

#endif _WALLET_H_
