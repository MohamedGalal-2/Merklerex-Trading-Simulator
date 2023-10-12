#include "..\Header Files\orderBookEntry.h"

orderBookEntry::orderBookEntry(
	double _price,
	double _amount,
	std::string _timestamp,
	std::string _product,
	orderBookType _orderType)
	: price(_price),
	amount(_amount),
	timestamp(_timestamp),
	product(_product),
	orderType(_orderType)
{

}