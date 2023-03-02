#include <iostream>
#include <fstream>

int main()
{
	std::fstream file;
	std::string text;

	file.open("mecz.txt", std::ios::in);

	if (file.good())
	{
		file >> text;
	}

	file.close();

	int differences = 0;

	int teamA = 0;
	int teamB = 0;

	int wins = 0;
	int streaks = 0;
	int longestWin = 0;
	char longestWinTeam = '-';

	for (int i = 1; i < text.length(); i++)
	{
		char previous = text[i - 1];

		if (previous != text[i])
		{
			differences++;
		}
	}

	std::cout << "Wynik zadania 1.1: " << differences << std::endl;

//////////////////////////////////////////////////////////////

	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == 'A')
		{
			teamA++;
		}
		else
		{
			teamB++;
		}

		if (teamA >= 1000 || teamB >= 1000)
		{
			if (teamA - teamB >= 3)
			{
				std::cout << "Wynik zadania 1.2: A " << teamA << ":" << teamB << std::endl;
				break;
			}
			else if (teamB - teamA >= 3)
			{
				std::cout << "Wynik zadania 1.2: B " << teamA << ":" << teamB << std::endl;
				break;
			}
		}
	}

/////////////////////////////////////////////////////////////////////

	for (int i = 1; i < text.length(); i++)
	{
		char previous = text[i - 1];

		if (previous == text[i])
		{
			wins++;
		}
		else
		{
			if (wins > longestWin)
			{
				longestWin = wins;
				longestWinTeam = previous;
			}

			wins = 1;
		}

		if (wins == 10)
		{
			streaks++;
		}
	}

	std::cout << "Wynik zadania 1.3: " << streaks << " " << longestWinTeam << " " << longestWin << std::endl;

	return 0;
}