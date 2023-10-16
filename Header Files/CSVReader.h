/*File Guard*/
#pragma once
#ifndef _CSVRead_H_
#define _CSVRead_H_

/*Includes Section*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "orderBookEntry.h"
using namespace std;

/*Class Section*/
class CSVReader
{
public:
	CSVReader();

	static std::vector<orderBookEntry> readCSV(std::string csvFile);

private:
	static std::vector<std::string> parse(std::string csvLine, char separator);
	static orderBookEntry parseLine(std::vector<std::string> strings);

};
#endif // _CSVRead_H_