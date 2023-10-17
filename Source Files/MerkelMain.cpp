#include "..\Header Files\MerkelMain.h"

MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
	// Initialize variables
	int input = 0;
	currentTime = orderBook.getEarliestTime();

	// Print welcome message
	cyan();
	std::cout << "Welcome to the Merklerex exchange!" << endl;
	reset();

	// Load order book
	while (input != 7)
	{
		// Print menu
		printMenu();

		// Get user 
		input = getUserOption();

		// Process user input
		processUserOption(input);

	}
}

void MerkelMain::printMenu()
{
	// Print options
	std::cout << "======================" << endl;
	std::cout << "Current time: " << currentTime << endl;
	yellow();
	std::cout << "1. Print help" << endl
		<< "2. Print exchange stats" << endl
		<< "3. Make an offer" << endl
		<< "4. Make a bid" << endl
		<< "5. Print wallet" << endl
		<< "6. Continue" << endl
		<< "7. Exit" << endl;
	cout << "======================" << endl;
	reset();
}

void MerkelMain::printHelp()
{
	std::cout << "This is the help section." << endl;
	magenta();
	std::cout << "Your aim is to make money, analyse the market, and make bids and offers." << endl;
	reset();
}

void MerkelMain::printMarketStats()
{
	magenta();
	std::cout << "The exchange stats are as follows:" << endl;
	reset();

	for (std::string const& prod : orderBook.getKnownProducts())
	{
		blue();
		std::cout << "Product: " << prod << std::endl;
		std::vector<orderBookEntry> enteries = orderBook.getOrders(prod, orderBookType::ask, currentTime);
		cyan();
		std::cout << "Asks: " << enteries.size() << std::endl;
		reset();
		std::cout << "Max ask: " << orderBook::getHighPrice(enteries) << std::endl;
		std::cout << "Min ask: " << orderBook::getLowPrice(enteries) << std::endl;
		std::cout << "Total ask amount: " << orderBook::getAmountAsk(enteries) << std::endl;
	}

	//unsigned int bidsNumber = 0;
	//unsigned int asksNumber = 0;
	//for (orderBookEntry& e : orders)
	//{
	//	if (e.orderType == orderBookType::ask)
	//	{
	//		asksNumber++;
	//	}
	//	else if (e.orderType == orderBookType::bid)
	//	{
	//		bidsNumber++;
	//	}
	//}
	//std::cout << "Order Book contains (" << asksNumber << ") asks and (" << bidsNumber << ") bids." << endl;
}

void MerkelMain::makeAsk()
{
	magenta();
	std::cout << "Make an ask - enter the amount: product,price,amount, eg. ETH/BTC,200.02,0.5 " << endl;
	std::string input;

	// Get user input
	std::getline(std::cin, input);
	// Parse user input
	std::vector<std::string> tokens = CSVReader::parse(input, ',');
	if (3 != tokens.size())
	{
		red();
		std::cout << "MerkelMain::makeAsk-> Data isn't complete!" << endl;
		reset();
		return;
	}
	else
	{
		try
		{
			orderBookEntry entry = CSVReader::parseLine(tokens[1], tokens[2], currentTime, tokens[0], orderBookType::ask);
			orderBook.insertOrder(entry);
		}
		catch (const std::exception& e)
		{
			red();
			std::cout << "MerkelMain::makeAsk-> Invalid Data!" << endl;
			reset();
			return;
		}
	}


	std::cout << "You entered: " << input << endl;

	reset();
}

void MerkelMain::enterBid()
{
	magenta();
	std::cout << "Make a bid - enter the amount: product,price,amount, eg. ETH/BTC,200.02,0.5 " << endl;
	std::string input;

	// Get user input
	std::getline(std::cin, input);
	// Parse user input
	std::vector<std::string> tokens = CSVReader::parse(input, ',');
	if (3 != tokens.size())
	{
		red();
		std::cout << "MerkelMain::makeAsk-> Data isn't complete!" << endl;
		reset();
		return;
	}
	else
	{
		try
		{
			orderBookEntry entry = CSVReader::parseLine(tokens[1], tokens[2], currentTime, tokens[0], orderBookType::bid);
			orderBook.insertOrder(entry);
		}
		catch (const std::exception& e)
		{
			red();
			std::cout << "MerkelMain::enterBid-> Invalid Data!" << endl;
			reset();
			return;
		}
	}
	blue();
	std::cout << "You entered: " << input << endl;
	reset();
}

void MerkelMain::printWallet()
{
	std::cout << "This is the print wallet section." << endl;
	magenta();
	std::cout << "You can print your wallet here." << endl;
	reset();
}

void MerkelMain::gotoNextTimeFrame()
{
	currentTime = orderBook.getNextTime(currentTime);
	magenta();
	std::cout << "You can continue here." << endl;
	reset();
}

void MerkelMain::printExit()
{
	red();
	std::cout << "Thanks for using Merklerex!" << endl;
	reset();
}

int MerkelMain::getUserOption()
{
	int userOption = 0;
	std::string line;

	// Get user input
	std::cout << "Please enter your option: ";
	std::getline(std::cin, line);
	// Convert user input to integer
	try
	{
		userOption = std::stoi(line);
	}
	catch (const std::exception& e)
	{
		red();
		std::cout << "MerkelMain::getUserOption-> Invalid option!" << endl;
		reset();
	}

	return userOption;
}

void MerkelMain::processUserOption(int userOption)
{
	// Check if user input is valid
	if (userOption > 7 || userOption < 1)
	{
		red();
		std::cout << "MerkelMain::processUserOption-> Invalid option!" << endl;
		reset();
	}

	// Perform action based on user input
	switch (userOption)
	{
	case 1:
		printHelp();
		break;

	case 2:
		printMarketStats();
		break;

	case 3:
		makeAsk();
		break;

	case 4:
		enterBid();
		break;

	case 5:
		printWallet();
		break;

	case 6:
		gotoNextTimeFrame();
		break;

	case 7:
		printExit();
		break;
	}
}

