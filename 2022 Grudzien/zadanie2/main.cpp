#include <iostream>
#include <fstream>
#include <string>


bool canGoToY(int firstNumber, int secoundNumber)
{
	firstNumber *= 2;

	if (firstNumber > secoundNumber)
	{
		return false;
	}

	if (firstNumber == secoundNumber || firstNumber + 1 == secoundNumber)
	{
		return true;
	}
	else
	{
		if (canGoToY(firstNumber, secoundNumber) == true)
		{
			return true;
		}
		else
		{
			return canGoToY(firstNumber + 1, secoundNumber);
		}
	}
}

void getPairs(std::string line)
{
	std::string number;
	int firstNumber = 0;
	int secoundNumber = 0;


	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] != ' ')
		{
			number += line[i];
		}
		else
		{
			firstNumber = std::stoi(number);
			number = "";
		}
	}

	secoundNumber = std::stoi(number);

	if (canGoToY(firstNumber, secoundNumber) == true)
	{
		std::cout << firstNumber << " " << secoundNumber << std::endl;
	}
}



int main()
{
	std::fstream file;

	std::string line;

	file.open("pary.txt", std::ios::in | std::ios::binary);

	std::getline(file, line);

	while (!file.eof())
	{
		std::getline(file, line);

		if (line != "")
		{
			getPairs(line);
		}
	}

	file.close();

	return 0;
}