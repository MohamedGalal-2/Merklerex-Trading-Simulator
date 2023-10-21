#include "..\Header Files\orderBookEntry.h"

orderBookEntry::orderBookEntry(
	double _price,
	double _amount,
	std::string _timestamp,
	std::string _product,
	orderBookType _orderType,
	std::string _username)
	: price(_price),
	amount(_amount),
	timestamp(_timestamp),
	product(_product),
	orderType(_orderType),
	username(_username)
{
	// empty
}

/**
  * @brief Converts a string to an orderBookType
  * @param string The string to convert
  * @return The orderBookType
  * @note If the string is not a valid orderBookType, returns orderBookType::unknown
  */
orderBookType orderBookEntry::stringToOrderBookType(std::string string)
{
	orderBookType orderType;
	if (string == "ask")
	{
		orderType = orderBookType::ask;
	}
	else if (string == "bid")
	{
		orderType = orderBookType::bid;
	}
	else
	{
		orderType = orderBookType::unknown;
	}

	return orderType;
}