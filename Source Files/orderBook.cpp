#include "..\Header Files\orderBook.h"

/*Constructors Section*/
orderBook::orderBook(std::string filename)
{
	orders = CSVReader::readCSV(filename);
}

/**
  * @brief Get a list of all the known products present in the order book
  * @return std::vector<orderBookEntry> - The available products
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
  * @brief Get the Orders object for a specific product, type, and timestamp
  * @param product - The product to get the orders for
  * @param type - The type of order to get
  * @param timestamp - The time frame to get the orders for
  * @return std::vector<orderBookEntry> - The orders that match the criteria
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

/**
  * @brief Get the Highest Price of each product during the time frame
  * @param orders - The orders to get the price from
  * @return double - The highest price
  */
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

/**
  * @brief Get the Lowest Price of each product during the time frame
  * @param orders - The orders to get the price from
  * @return double - The lowest price
  */
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

/**
  * @brief Get the asked amount of each product during the time frame
  * @param orders - The orders to get the amount from
  * @return double - The amount asked
  * @note This is the sum of all the orders
  */
double orderBook::getAmountAsk(std::vector<orderBookEntry>& orders)
{
	double amount_Ask = 0.0;

	for (orderBookEntry& entry : orders)
	{
		amount_Ask += entry.amount;
	}

	return amount_Ask;
}

/**
  * @brief Get the first Time frame
  * @return std::string - First timestamp
  */
std::string orderBook::getEarliestTime()
{
	return orders[0].timestamp;
}

/**
  * @brief Get the Next Timestamp frame
  * @param timestamp - Current timestamp
  * @return std::string - Next timestamp
  * @note If there is no next time, wraps around to start.
  */
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

/**
  * @brief  Insert an order into the order book
  * @param  order
  * @return void
  */
void orderBook::insertOrder(orderBookEntry& order)
{
	orders.push_back(order);
	std::sort(orders.begin(), orders.end(), orderBookEntry::compareTimestamp);
}

/**t
  * @brief  Matching algorithm that matches asks to bids during the time frame
  * @param  product - The product to match
  * @param  Timestamp - The timestamp frame the matching occurs at
  * @return std::vector<orderBookEntry> - The sales that occured
  */
std::vector<orderBookEntry> orderBook::matchingEngine(std::string product, std::string timestamp)
{
	// Get the asks for the product and timestamp
	std::vector<orderBookEntry> asks = getOrders(product, orderBookType::ask, timestamp);

	// Get the bids for the product and timestamp
	std::vector<orderBookEntry> bids = getOrders(product, orderBookType::bid, timestamp);

	// The sales that occured
	std::vector<orderBookEntry> sales;

	// Sort asks ascending by price
	std::sort(asks.begin(), asks.end(), orderBookEntry::compareByPriceAsc);

	// Sort bids descending by price
	std::sort(bids.begin(), bids.end(), orderBookEntry::compareByPriceDesc);

	// For each ask
	for (orderBookEntry& asksEntry : asks)
	{
		// For each bid
		for (orderBookEntry& bidsEntry : bids)
		{
			if (bidsEntry.price >= asksEntry.price)
			{
				// Create a sale with the ask price
				orderBookEntry sale
				{
					asksEntry.price,
					0.0,
					timestamp,
					product,
					orderBookType::asksale
				};

				if (bidsEntry.username == "simuser")
				{
					sale.username = "simuser";
					sale.orderType = orderBookType::bidsale;
				}
				else if (asksEntry.username == "simuser")
				{
					sale.username = "simuser";
					sale.orderType = orderBookType::asksale;
				}

				if (bidsEntry.amount == asksEntry.amount)
				{
					sale.amount = asksEntry.amount;

					sales.push_back(sale);

					bidsEntry.amount = 0;

					break;
				}
				else if (bidsEntry.amount > asksEntry.amount)
				{
					sale.amount = asksEntry.amount;

					sales.push_back(sale);

					bidsEntry.amount -= asksEntry.amount;

					break;

				}
				else if ((bidsEntry.amount < asksEntry.amount) && (bidsEntry.amount > 0))
				{
					sale.amount = bidsEntry.amount;

					sales.push_back(sale);

					asksEntry.amount -= bidsEntry.amount;

					bidsEntry.amount = 0;

					continue;
				}
				else
				{
					// Do nothing
				}
			} // End of if bid price >= ask price
		} // End of for each bid
	} // End of for each ask

	return sales;
}
