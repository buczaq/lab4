#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int toBinary(int n, int k = 1)
{
	bool flag = 0;
	unsigned long long int result = n*k;
	while(result)
	{
		if (result%10 > 1) flag = 1;
		result /= 10;
	}
	if (!flag) return k;
	else toBinary(n, ++k);
}

void numbersToWords(int number)
{
	int tempNumber = number;
	int counter = 0;
	int numbersInNumber[6] = {0,0,0,0,0,0};
	std::string result[6] = {" ", " ", " ", " ", " ", " "};
	const std::string numerals[4][9] = {
		{"jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"},
		{"dziesiec", "dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"},
		{"sto", "dwiescie", "trzysta", "czterysta","piecset", "szescset", "siedemset", "osiemset", "dziewiecset"},
		{"jedenascie", "dwanascie", "trzynascie", "czternascie", "pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie" }
		};

	for (int i = 0; i <= 6; i++)
	{
		numbersInNumber[i] = number%10;
		number/=10;
	}
	
	while (counter <=6)
	{
		if (((counter == 1) && (numbersInNumber[1] == 1) && numbersInNumber[0]!=0)||(counter == 4 && numbersInNumber[4] == 1 && numbersInNumber[3]!=0))
		{
			result[counter] = numerals[3][numbersInNumber[counter]-1];
			result[counter-1] = " ";
		}
		else if (numbersInNumber[counter])
		{
			result[counter] = numerals[counter%3][numbersInNumber[counter]-1];
		}
		counter++;
	}
	for (int i = 5; i>=0; i--)
	{
		if(i == 2)
		{
			if (tempNumber>999)
			{
			if ((numbersInNumber[3] == 1 && numbersInNumber[4]!=1 && numbersInNumber[4]!=0) || (numbersInNumber[3] == 1 && numbersInNumber[4] == 0 && numbersInNumber[5] == 0)) cout << "tysiac ";
			else if ((numbersInNumber[3] == 0 || numbersInNumber[3] > 4 || numbersInNumber[4] == 1) || (numbersInNumber[3] == 1 && numbersInNumber[4] == 0)) cout << "tysiecy ";
			if (numbersInNumber[3] > 1 && numbersInNumber[3] <= 4) cout << "tysiace ";
			}
		}
		if (result[i]!=" ") cout << result[i] << " ";
	}
	cout << "\n";
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	numbersToWords(n);
	cout << "razy\n";
	numbersToWords(toBinary(n));
	cout << "to liczba skladajaca sie z samych zer i jedynek\n\n";
}