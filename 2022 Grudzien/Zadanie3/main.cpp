#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;


void howManyPrimes(vector<int> &primeNumbers, vector<int> &numbers)
{
    int howMany = 0;

    for(unsigned int i = 0; i < numbers.size() - 1; i++)
    {
        for(unsigned int j = 0; j < primeNumbers.size(); j++)
        {
            if(numbers[i] - 1 == primeNumbers[j])
            {
                //cout << numbers[i] - 1 << " - " << primeNumbers[j] << endl;
                howMany++;
                break;
            }
        }
    }

    cout << "3.2:  " << howMany << endl;
}


void calculatePrimeNumbers(vector<int> &primeNumbers, int N)
{
    bool SITO[N];

    for(int i = 0; i < N; i++)
    {
        SITO[i] = true;
    }

    SITO[1] = false;

    for(int i = 1; i < sqrt(N); i++)
    {
        if(SITO[i] == true)
        {
            for(int j = 2; j * i < N; j++)
            {
                SITO[j * i] = false;
            }
        }
    }


    for(int i = 1; i < N; i++)
    {
        if(SITO[i] == true)
        {
            primeNumbers.push_back(i);
        }
    }
}

int main()
{
    int biggestNumber = 0;

    vector<int> numbers;
    vector<int> primeNumbers;

    fstream file;

    file.open("liczby_przyklad.txt", ios::in);

    if(file.good())
    {

        int number;

        while(!file.eof())
        {
            file >> number;
            numbers.push_back(number);

            if(number > biggestNumber)
            {
                biggestNumber = number;
            }
        }
    }

    file.close();

    calculatePrimeNumbers(primeNumbers, biggestNumber);

    howManyPrimes(primeNumbers, numbers);

    return 0;
}
