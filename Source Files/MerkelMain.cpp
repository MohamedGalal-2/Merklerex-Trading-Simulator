#include "..\Header Files\MerkelMain.h"
#include "..\Header Files\colors.h"
#include "..\Header Files\orderBookEntry.h"

MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
	// Initialize variables
	int input = 0;

	// Print welcome message
	cyan();
	std::cout << "Welcome to the Merklerex exchange!" << endl;
	reset();

	// Load order book
	loadOrderBook();
	while (input != 7)
	{
		// Print menu
		printMenu();

		// Get user 
		input = getUserOption(input);

		// Process user input
		processUserOption(input);
	}
}

void MerkelMain::loadOrderBook()
{
	std::string path;
	path = "C:/Users/lolo7/Desktop/Projects/CPP Projects/OOP/OOP/orderBookDataSet.csv";
	orders = CSVReader::readCSV(path);
}

void MerkelMain::printMenu()
{
	// Print options
	yellow();
	std::cout << "1. Print help" << endl
		<< "2. Print exchange stats" << endl
		<< "3. Make an offer" << endl
		<< "4. Make a bid" << endl
		<< "5. Print wallet" << endl
		<< "6. Continue" << endl
		<< "7. Exit" << endl;
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
	blue();
	std::cout << "Order Book contains (" << orders.size() << ") entries." << endl;
	reset();

	unsigned int bidsNumber = 0;
	unsigned int asksNumber = 0;
	for (orderBookEntry& e : orders)
	{
		if (e.orderType == orderBookType::ask)
		{
			asksNumber++;
		}
		else if (e.orderType == orderBookType::bid)
		{
			bidsNumber++;
		}
	}
	std::cout << "Order Book contains (" << asksNumber << ") asks and (" << bidsNumber << ") bids." << endl;
}

void MerkelMain::makeOffer()
{
	std::cout << "This is the make an offer section." << endl;
	magenta();
	std::cout << "You can make an offer here." << endl;
	reset();
}

void MerkelMain::enterBid()
{
	std::cout << "This is the make a bid section." << endl;
	magenta();
	std::cout << "You can make a bid here." << endl;
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
	std::cout << "This is the continue section." << endl;
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

int MerkelMain::getUserOption(int userOption)
{
	// Get user input
	std::cout << "Please enter your option: ";
	std::cin >> userOption;

	return userOption;
}

void MerkelMain::processUserOption(int userOption)
{
	// Check if user input is valid
	if (userOption > 7 || userOption < 1)
	{
		red();
		std::cout << "Invalid option!" << endl;
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
		makeOffer();
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

