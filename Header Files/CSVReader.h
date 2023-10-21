/*File Guard*/
#pragma once
#ifndef _CSVRead_H_
#define _CSVRead_H_

/*Includes Section*/
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "..\Header Files\orderBookEntry.h"
using namespace std;


/*Class Section*/
class CSVReader
{
public:
	/** Constructor */
	CSVReader();

	/**
	  * @brief  This function reads a CSV file and returns a vector of orderBookEntry objects
	  * @param  csvFile - The name of the CSV file to read
	  * @return A vector of orderBookEntry objects
	  */
	static std::vector<orderBookEntry> readCSV(std::string csvFile);

	/**
	  * @brief  This function parses a CSV line and returns a vector of strings
	  * @param  csvLine - The CSV line to parse
	  * @param  separator - The character used to separate the CSV fields
	  * @return A vector of strings
	  */
	static std::vector<std::string> parse(std::string csvLine, char separator);

	/**
	  * @brief  This function parses a CSV line and returns an orderBookEntry object
	  * @param  price - The price of the order
	  * @param  amount - The amount of the order
	  * @param  timestamp - The timestamp of the order
	  * @param  product - The product of the order
	  * @param  orderType - The type of the order
	  * @return An orderBookEntry object
	  */
	static orderBookEntry parseLine(std::string price, std::string amount,
		std::string timestamp, std::string product, orderBookType orderType);

private:
	/**
	  * @brief  This function parses a vector of strings and returns an orderBookEntry object
	  * @param  strings - The vector of strings to parse
	  * @return An orderBookEntry object
	  */
	static orderBookEntry parseLine(std::vector<std::string> strings);

};
#endif // _CSVRead_H_