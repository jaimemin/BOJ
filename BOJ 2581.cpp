#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10000 + 100;

int minFactor[MAX];

void eratosthenes()
{
	minFactor[0] = minFactor[1] = -1;

	for (int i = 2; i < MAX; i++)
	{
		minFactor[i] = i;
	}

	for (int i = 2; i * i < MAX; i++)
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
	int M, N;
	cin >> M >> N;

	eratosthenes();
	vector<int> primes;

	for (int i = M; i <= N; i++)
	{
		if (minFactor[i] == i)
		{
			primes.push_back(i);
		}
	}

	if (primes.empty())
	{
		cout << -1 << "\n";

		return 0;
	}

	int sum = 0;

	for (int num : primes)
	{
		sum += num;
	}

	cout << sum << "\n" << primes[0] << "\n";

	return 0;
}