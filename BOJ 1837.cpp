#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 1000000 + 1;

int minFactor[MAX];
vector<int> primeNumbers;

void eratosthenes(int K)
{
	minFactor[0] = minFactor[1] = -1;

	for (int i = 2; i < K; i++)
	{
		minFactor[i] = i;
	}

	for (int i = 2; i*i < K; i++)
	{
		if (minFactor[i] == i)
		{
			for (int j = i * i; j < K; j += i)
			{
				if (minFactor[j] == j)
				{
					minFactor[j] = i;
				}
			}
		}
	}

	for (int i = 2; i < K; i++)
	{
		if (minFactor[i] == i)
		{
			primeNumbers.push_back(i);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string p;
	int K;
	cin >> p >> K;

	eratosthenes(K);

	for (int primeNumber : primeNumbers)
	{
		int div = 0, temp = 1;

		for (int i = p.length() - 1; i >= 0; i--)
		{
			div = (div + (p[i] - '0') * temp) % primeNumber;

			temp *= 10;
			temp %= primeNumber;
		}

		if (div == 0)
		{
			cout << "BAD " << primeNumber << "\n";

			return 0;
		}
	}

	cout << "GOOD\n";

	return 0;
}