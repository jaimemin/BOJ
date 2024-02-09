#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e7 + 10;

int minFactor[MAX];
vector<int> primes;

void eratosthenes()
{
	for (int i = 0; i < MAX; i++)
	{
		minFactor[i] = i;
	}

	minFactor[0] = minFactor[1] = -1;

	for (int i = 2; i * i < MAX; i++)
	{
		if (minFactor[i] == i)
		{
			continue;
		}

		for (int j = i * i; j < MAX; j += i)
		{
			if (minFactor[j] == j)
			{
				minFactor[j] = i;
			}
		}
	}

	for (int i = 2; i < MAX; i++)
	{
		if (minFactor[i] == i)
		{
			primes.push_back(i);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	eratosthenes();
	int idx = 0;

	while (N != 1)
	{
		while (N % primes[idx] == 0)
		{
			cout << primes[idx] << "\n";

			N /= primes[idx];
		}

		idx++;
	}

	return 0;
}