/*Includes Section*/
#include "..\Header Files\CSVReader.h"

CSVReader::CSVReader()
{

}

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
				cout << "CSVReader::readCSV Bad line!!" << line << std::endl;
				continue;
			}
			orderBookEntry entry = parseLine(parse(line, ','));
			entries.push_back(entry);
		} // end of getline while
		reader.close();
	} // end of reader is open if
	else
	{
		cout << "Bad data file! Cannot access!" << endl;
		return entries;
	}

	return entries;
}

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
		std::cout << "Bad Float!!" << tokens[3] << std::endl;
		std::cout << "Bad Float!!" << tokens[4] << std::endl;
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