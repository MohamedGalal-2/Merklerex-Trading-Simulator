/*File Guard*/
#pragma once
#ifndef _ORDERBOOKENTRY_H_
#define _ORDERBOOKENTRY_H_

/*Includes Section*/
#include <string>
#include <vector>
using namespace std;

// Variables for the order book
enum class orderBookType // Type of the ask/bid
{
	bid,
	ask,
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
		orderBookType _orderType);

	static orderBookType stringToOrderBookType(std::string string);

	// Getters
	orderBookType orderType;	// Type of the ask/bid
	double price;				// Price of the ask/bid
	double amount;				// Amount of the ask/bid
	std::string timestamp;		// Timestamp of the ask/bid	
	std::string product;		// Product of the ask/bid
};

#endif // _ORDERBOOKENTRY_H_


