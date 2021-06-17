#include <iostream>
using namespace std;

const int MAX = 10000000;

int minFactor[MAX];

void eratosthenes(void)
{
	minFactor[0] = minFactor[1] = -1;

	for (int i = 2; i < MAX; i++)
	{
		minFactor[i] = i;
	}

	for (int i = 2; i*i < MAX; i++)
	{
		if (minFactor[i] == i)
		{
			for (int j = i * i; j < MAX; j += i)
			{
				if (minFactor[j] == j)
				{
					minFactor[j] = i;
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int pastNumber, additionalNumber;
	cin >> pastNumber >> additionalNumber;

	int newNumber = pastNumber + additionalNumber * 1e6;

	eratosthenes();

	if (minFactor[pastNumber] == pastNumber 
		&& minFactor[newNumber] == newNumber)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}

	return 0;
}