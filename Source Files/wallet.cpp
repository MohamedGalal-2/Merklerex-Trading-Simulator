#include "..\Header Files\wallet.h"

wallet::wallet()
{
};

void wallet::insrtIntoWallet(std::string type, double amount)
{
	double balance = 0.0;

	// if the currency is not in the wallet 
	if (0 == currencies.count(type))
	{
		balance = 0.0;
	}
	else if (amount < 0)
	{
		throw std::exception{};
	}
	else
	{
		balance = currencies[type];
	}
	balance += amount;
	currencies[type] = balance;
}

bool wallet::removeFromWallet(std::string type, double amount)
{
	bool state = false;

	if (0 == currencies.count(type))
	{
		state = false;
	}
	else if (amount < 0)
	{
		state = false;
	}
	else if (currencies[type] < amount)
	{
		state = false;
	}
	else
	{
		if (checkWallet(type, amount))
		{
			currencies[type] -= amount;
			state = true;
		}
		else
		{
			state = false;
		}
	}

	return state;
}

bool wallet::checkWallet(std::string type, double amount)
{
	bool result = false;
	if (0 == currencies.count(type))
	{
		result = false;
	}
	else if (currencies[type] >= amount)
	{
		result = true;
	}
	else
	{
		result = false;
	}
	return result;
}

bool wallet::isEnough(orderBookEntry order)
{
	bool result = false;
	double amount = 0.0;
	std::string currency;
	std::vector<std::string> currencies;

	currencies = CSVReader::parse(order.product, '/');

	if (order.orderType == orderBookType::bid)
	{
		amount = order.amount * order.price;
		currency = currencies[1];
		blue();
		cout << "Your order is to exchange (" << amount << ") " << currency << " for (" << order.price << ") " << currencies[0] << endl;
		reset();
		result = checkWallet(currency, amount);
	}
	else if (order.orderType == orderBookType::ask)
	{
		amount = order.amount;
		currency = currencies[0];
		blue();
		cout << "Your order is to exchange (" << amount << ") " << currency << " for (" << order.price << ") " << currencies[1] << " each." << endl;
		reset();
		result = checkWallet(currency, amount);
	}
	else
	{
		result = false;
	}

	return result;
}

std::string wallet::toString()
{
	std::string str;
	std::string currency;
	double amount = 0.0;

	for (std::pair<std::string, double> pair : currencies)
	{
		currency = pair.first;
		amount = pair.second;
		str += std::to_string(amount) + " of " + currency + "\n";
	}

	return str;
}

void wallet::processSale(orderBookEntry& sale)
{
	bool result = false;
	double outgoingAmount = 0.0;
	double incomingAmount = 0.0;
	std::string outgoingCurrency;
	std::string incomingCurrency;
	std::vector<std::string> currs;

	currs = CSVReader::parse(sale.product, '/');

	if (sale.orderType == orderBookType::asksale)
	{
		outgoingAmount = sale.amount;
		outgoingCurrency = currs[0];
		incomingAmount = sale.amount * sale.price;
		incomingCurrency = currs[1];

		currencies[incomingCurrency] += incomingAmount;
		currencies[outgoingCurrency] -= outgoingAmount;
	}
	else if (sale.orderType == orderBookType::bidsale)
	{
		incomingAmount = sale.amount;
		incomingCurrency = currs[0];
		outgoingAmount = sale.amount * sale.price;
		outgoingCurrency = currs[1];

		currencies[incomingCurrency] += incomingAmount;
		currencies[outgoingCurrency] -= outgoingAmount;
	}
	else
	{
		// Do nothing
	}

}
