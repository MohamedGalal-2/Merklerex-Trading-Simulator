/*File Guard*/
#pragma once
#ifndef _MERKELMAIN_H_
#define _MERKELMAIN_H_

/*Includes Section*/
#include <iostream>
#include <string>
#include <vector>
#include "orderBookEntry.h"
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
	void loadOrderBook();
	void printHelp();
	void printMarketStats();
	void makeOffer();
	void enterBid();
	void printWallet();
	void gotoNextTimeFrame();
	void printExit();
	void printMenu();
	int  getUserOption(int userOption);
	void processUserOption(int userOption);

	std::vector<orderBookEntry> orders;		// Vector of order book entries
};

#endif // _MERKELMAIN_H_