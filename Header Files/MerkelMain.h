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
#include "..\Header Files\wallet.h"
using namespace std;

class MerkelMain
{
public:
	/** Constructor */
	MerkelMain();

	/**
	  * @brief This function is used to initialize the MerkelMain class
	  * @param void
	  * @return void
	  */
	void init(void);

private:
	/**
	  * @brief This function is used to print the menu
	  * @param void
	  * @return void
	  */
	void printHelp(void);

	/**
	  * @brief This function is used to print the market stats
	  * @param void
	  * @return void
	  */
	void printMarketStats(void);

	/**
	  * @brief This function is used to enter an ask order to the book
	  * @param void
	  * @return void
	  */
	void makeAsk(void);

	/**
	  * @brief This function is used to enter a bid order to the book
	  * @param void
	  * @return void
	  */
	void enterBid(void);

	/**
	  * @brief This function is used to print the wallet of the user
	  * @param void
	  * @return void
	  */
	void printWallet(void);

	/**
	  * @brief This function is used to skip to the next time frame and process the exhange of orders
	  * @param void
	  * @return void
	  */
	void gotoNextTimeFrame(void);

	/**
	  * @brief This function is used to print the exit message
	  * @param void
	  * @return void
	  */
	void printExit(void);

	/**
	  * @brief This function is used to print the menu
	  * @param void
	  * @return void
	  */
	void printMenu(void);

	/**
	  * @brief This function is used to get the user option
	  * @param void
	  * @return int
	  */
	int  getUserOption(void);

	/**
	  * @brief This function is used to process the user option
	  * @param int
	  * @return void
	  */
	void processUserOption(int userOption);

	std::string currentTime;
	std::string nextTime;

	/** 
	  * @brief - Select the path of the order book data set
	  */
	orderBook orderBook{ "C:/Users/Mohamed-Galal/Desktop/Projects/CPP Programming/Merklerex-Trading-Simulator/orderBookDataSet.csv" };
	std::vector<orderBookEntry> orders;		// Vector of order book entries

	wallet wallet;
};

#endif // _MERKELMAIN_H_