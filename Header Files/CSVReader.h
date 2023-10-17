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
	CSVReader();

	static std::vector<orderBookEntry> readCSV(std::string csvFile);
	static std::vector<std::string> parse(std::string csvLine, char separator);
	static orderBookEntry parseLine(std::string price, std::string amount,
		std::string timestamp, std::string product, orderBookType orderType);

private:
	
	static orderBookEntry parseLine(std::vector<std::string> strings);

};
#endif // _CSVRead_H_