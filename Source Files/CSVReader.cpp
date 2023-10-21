/*Includes Section*/
#include "..\Header Files\CSVReader.h"

/** Constructor */
CSVReader::CSVReader()
{

}

/**
  * @brief  This function reads a CSV file and returns a vector of orderBookEntry objects
  * @param  csvFile - The name of the CSV file to read
  * @return A vector of orderBookEntry objects
  */
std::vector<orderBookEntry> CSVReader::readCSV(std::string csvFilename)
{
	std::vector<orderBookEntry> entries;
	std::ifstream reader{ csvFilename };
	std::string line;

	if (reader.is_open())
	{
		while (std::getline(reader, line))
		{
			try
			{
				orderBookEntry entry = parseLine(parse(line, ','));
			}
			catch (const std::exception& e)
			{
				// cout << "CSVReader::readCSV Bad line!!" << line << std::endl;
				continue;
			}
			orderBookEntry entry = parseLine(parse(line, ','));
			entries.push_back(entry);
		} // end of getline while
		reader.close();
	} // end of reader is open if
	else
	{
		// cout << "Bad data file! Cannot access!" << endl;
		return entries;
	}

	return entries;
}

/**
  * @brief  This function parses a CSV line and returns a vector of strings
  * @param  csvLine - The CSV line to parse
  * @param  separator - The character used to separate the CSV fields
  * @return A vector of strings
  */
std::vector<std::string> CSVReader::parse(std::string csvLine, char separator)
{
	std::vector<std::string> tokens;
	signed int start, end;
	std::string token;
	start = csvLine.find_first_not_of(separator, 0);

	do
	{
		end = csvLine.find_first_of(separator, start);
		if (start == csvLine.length() || start == end)
		{
			break;
		}
		else if (end >= 0)
		{
			token = csvLine.substr(start, end - start);
		}
		else
		{
			token = csvLine.substr(start, csvLine.length() - start);
		}
		tokens.push_back(token);

		start = end + 1;

	} while (end != std::string::npos);

	return tokens;
}

/**
  * @brief  This function parses a CSV line and returns an orderBookEntry object
  * @param  price - The price of the order
  * @param  amount - The amount of the order
  * @param  timestamp - The timestamp of the order
  * @param  product - The product of the order
  * @param  orderType - The type of the order
  * @return An orderBookEntry object
  */
orderBookEntry CSVReader::parseLine(std::vector<std::string> tokens)
{
	double price, amount;

	if (tokens.size() != 5) //bad 
	{
		throw std::exception();
	}

	// We have 5 tokens
	try
	{
		price = std::stod(tokens[3]);
		amount = std::stod(tokens[4]);
	}
	catch (const std::exception& e)
	{
		// std::cout << "Bad Float!!" << tokens[3] << std::endl;
		// std::cout << "Bad Float!!" << tokens[4] << std::endl;
		throw;
	}

	orderBookEntry entry
	{
		price,
		amount,
		tokens[0],
		tokens[1],
		orderBookEntry::stringToOrderBookType(tokens[2])
	};

	return entry;
}

/**
  * @brief  This function parses a vector of strings and returns an orderBookEntry object
  * @param  strings - The vector of strings to parse
  * @return An orderBookEntry object
  */
orderBookEntry CSVReader::parseLine(std::string price, std::string amount,
	std::string timestamp, std::string product, orderBookType orderType)
{
	double _price, _amount;

	try
	{
		_price = std::stod(price);
		_amount = std::stod(amount);
	}
	catch (const std::exception& e)
	{
		// std::cout << "Bad Float!!" << price << std::endl;
		// std::cout << "Bad Float!!" << amount << std::endl;
		throw;
	}

	orderBookEntry entry
	{
		_price,
		_amount,
		timestamp,
		product,
		orderType
	};

	return entry;
}