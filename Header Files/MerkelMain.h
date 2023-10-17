/*File Guard*/
#pragma once
#ifndef _MERKELMAIN_H_
#define _MERKELMAIN_H_

/*Includes Section*/
#include <iostream>
#include <string>
#include <vector>
#include "..\Header Files\orderBookEntry.h"
#include "..\Header Files\colors.h"
#include "..\Header Files\CSVReader.h"
#include "..\Header Files\orderBook.h"
using namespace std;

class MerkelMain
{
public:
	MerkelMain();
	/**
	  * @brief This function is used to initialize the MerkelMain class
	  * @param None
	  * @return None
	  */
	void init();
private:
	void printHelp();
	void printMarketStats();
	void makeAsk();
	void enterBid();
	void printWallet();
	void gotoNextTimeFrame();
	void printExit();
	void printMenu();
	int  getUserOption();
	void processUserOption(int userOption);

	std::string currentTime;
	std::string nextTime;

	orderBook orderBook{ "C:/Users/lolo7/Desktop/Projects/CPP Projects/OOP/OOP/orderBookDataSet.csv" };
	std::vector<orderBookEntry> orders;		// Vector of order book entries
};

#endif // _MERKELMAIN_H_