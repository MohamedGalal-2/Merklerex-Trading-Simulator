#include "..\Header Files\orderBook.h"

/*Constructors Section*/
orderBook::orderBook(std::string filename)
{
	orders = CSVReader::readCSV(filename);
}

/**
* @brief Get the Known Products object
*
*/
std::vector<std::string> orderBook::getKnownProducts()
{
	std::vector<std::string> products;
	std::map<std::string, bool> productMap;

	for (orderBookEntry& entry : orders)
	{
		productMap[entry.product] = true;
	}

	for (auto const& entry : productMap)
	{
		products.push_back(entry.first);
	}

	return products;
}

/**
* @brief Get the Orders object
* @param product
* @param type
* @param timestamp
* @return std::vector<orderBookEntry>
*/
std::vector<orderBookEntry> orderBook::getOrders(std::string product, orderBookType type, std::string timestamp)
{
	std::vector<orderBookEntry> orders_;
	for (orderBookEntry& entry : orders)
	{
		if (entry.product == product && entry.orderType == type && entry.timestamp == timestamp)
		{
			orders_.push_back(entry);
		}
	}


	return orders_;
}

double orderBook::getHighPrice(std::vector<orderBookEntry>& orders)
{
	double max = orders[0].price;

	for (orderBookEntry& entry : orders)
	{
		if (entry.price > max)
		{
			max = entry.price;
		}
	}

	return max;
}

double orderBook::getLowPrice(std::vector<orderBookEntry>& orders)
{
	double min = orders[0].price;

	for (orderBookEntry& entry : orders)
	{
		if (entry.price < min)
		{
			min = entry.price;
		}
	}

	return min;
}

double orderBook::getAmountAsk(std::vector<orderBookEntry>& orders)
{
	double amount_Ask = 0.0;

	for (orderBookEntry& entry : orders)
	{
		amount_Ask += entry.amount;
	}

	return amount_Ask;
}

std::string orderBook::getEarliestTime()
{
	return orders[0].timestamp;
}

std::string orderBook::getNextTime(std::string timestamp)
{
	std::string nextTimestamp = "";

	for (orderBookEntry& entry : orders)
	{
		if (entry.timestamp > timestamp)
		{
			nextTimestamp = entry.timestamp;
			break;
		}
	}

	if (nextTimestamp == "")
	{
		nextTimestamp = orders[0].timestamp;
	}
	return nextTimestamp;
}

void orderBook::insertOrder(orderBookEntry& order)
{
	orders.push_back(order);
	std::sort(orders.begin(), orders.end(), orderBookEntry::compareTimestamp);
}
