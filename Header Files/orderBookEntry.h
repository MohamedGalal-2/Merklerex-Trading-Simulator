/*File Guard*/
#pragma once
#ifndef _ORDERBOOKENTRY_H_
#define _ORDERBOOKENTRY_H_

/*Includes Section*/
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// Variables for the order book
enum class orderBookType // Type of the ask/bid
{
	bid,
	ask,
	bidsale,
	asksale,
	unknown
};
// Order book entry class
class orderBookEntry
{
public:
	// Constructor
	orderBookEntry(
		double _price,
		double _amount,
		std::string _timestamp,
		std::string _product,
		orderBookType _orderType,
		std::string username = "dataset");

	/**
	  * @brief Converts a string to an orderBookType
	  * @param string The string to convert
	  * @return The orderBookType
	  * @note If the string is not a valid orderBookType, returns orderBookType::unknown
	  */
	static orderBookType stringToOrderBookType(std::string string);

	/**
	  * @brief This function compares two orderBookEntry objects by their timestamp
	  * @param order1 The first orderBookEntry
	  * @param order2 The second orderBookEntry
	  * @return True if order1.timestamp < order2.timestamp, false otherwise
	  */
	static bool compareTimestamp(orderBookEntry& order1, orderBookEntry& order2)
	{
		return order1.timestamp < order2.timestamp;
	}

	/**
		  * @brief This function compares two orderBookEntry objects by their price
		  * @param order1 The first orderBookEntry
		  * @param order2 The second orderBookEntry
		  * @return True if order1.price < order2.price, false otherwise
		  */
	static bool compareByPriceAsc(orderBookEntry& order1, orderBookEntry& order2)
	{
		return order1.price < order2.price;
	}

	/**
		  * @brief This function compares two orderBookEntry objects by their price
		  * @param order1 The first orderBookEntry
		  * @param order2 The second orderBookEntry
		  * @return True if order1.price > order2.price, false otherwise
		  */
	static bool compareByPriceDesc(orderBookEntry& order1, orderBookEntry& order2)
	{
		return order1.price > order2.price;
	}

	// Getters
	orderBookType orderType;
	double price;
	double amount;
	std::string timestamp;
	std::string product;
	std::string username;
};

#endif // _ORDERBOOKENTRY_H_


