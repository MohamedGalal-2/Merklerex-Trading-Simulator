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
#include "colors.h"
using namespace std;

class orderBook
{
public:
	/*Constructor*/
	orderBook(std::string filename);

/**
  * @brief Get all the available products in the order book during the time frame
  * @return std::vector<orderBookEntry> - The available products
  */
	std::vector<std::string> getKnownProducts();

/**
  * @brief Get the Orders object for a specific product, type, and timestamp
  * @param product - The product to get the orders for
  * @param type - The type of order to get
  * @param timestamp - The time frame to get the orders for
  * @return std::vector<orderBookEntry> - The orders that match the criteria
  */
	std::vector<orderBookEntry> getOrders(std::string product, orderBookType type, std::string timestamp);

/**
  * @brief Get the first Time frame
  * @return std::string - First timestamp
  */
	std::string getEarliestTime();

/**
  * @brief Get the Next Timestamp frame
  * @param timestamp - Current timestamp
  * @return std::string - Next timestamp
  * @note If there is no next time, wraps around to start.
  */
	std::string getNextTime(std::string timestamp);

/**
  * @brief  Insert an order into the order book
  * @param  order
  * @return void
  */
	void insertOrder(orderBookEntry& order);

/**
  * @brief Matching algorithm that matches asks to bids
  * @param product - The product to match
  * @param timestamp - The timestamp frame the matching occurs at
  * @return std::vector<orderBookEntry> - The sales that occured
  */
	std::vector<orderBookEntry> matchingEngine(std::string product, std::string timestamp);

/**
  * @brief Get the Highest Price of each product during the time frame
  * @param orders - The orders to get the price from
  * @return double - The highest price
  */
	static double getHighPrice(std::vector<orderBookEntry>& orders);

/**
  * @brief Get the Lowest Price of each product during the time frame
  * @param orders - The orders to get the price from
  * @return double - The lowest price
  */
	static double getLowPrice(std::vector<orderBookEntry>& orders);

/**
  * @brief Get the asked amount of each product
  * @param orders - The orders to get the amount from
  * @return double - The amount asked
  * @note This is the sum of all the orders
  */
	static double getAmountAsk(std::vector<orderBookEntry>& orders);

private:
	std::vector<orderBookEntry> orders;
};


#endif // _ORDERBOOK_H_