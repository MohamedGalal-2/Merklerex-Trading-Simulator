/*File Guard*/
#pragma once
#ifndef _ORDERBOOK_H_
#define _ORDERBOOK_H_

/*Includes Section*/
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include "orderBookEntry.h"
#include "CSVReader.h"
using namespace std;

class orderBook
{
public:
	/*Constructors Section*/
	orderBook(std::string filename);

	/**
	* @brief Get the Known Products object
	*
	*/
	std::vector<std::string> getKnownProducts();

	/**
	* @brief Get the Orders object

	*/
	std::vector<orderBookEntry> getOrders(std::string product, orderBookType type, std::string timestamp);

	/**
	*
	*/

	std::string getEarliestTime();
	/**
	*
	*
	* @note If there is no next time, wraps around to start.
	*/
	std::string getNextTime(std::string timestamp);

	void insertOrder(orderBookEntry& order);

	static double getHighPrice(std::vector<orderBookEntry>& orders);
	static double getLowPrice(std::vector<orderBookEntry>& orders);
	static double getAmountAsk(std::vector<orderBookEntry>& orders);


private:
	std::vector<orderBookEntry> orders;
};



#endif // _ORDERBOOK_H_