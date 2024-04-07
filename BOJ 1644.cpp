#include <iostream>
#include <vector>
using namespace std;

const int MAX = 4e6 + 400;

int N;

int result = 0;

int minFactor[MAX];

vector<int> primes;

void eratosthenes()
{
	minFactor[0] = minFactor[1] = -1;

	for (int i = 2; i < MAX; i++)
	{
		minFactor[i] = i;
	}

	for (int i = 2; i * i < MAX; i++)
	{
		if (minFactor[i] != i)
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

void func(int idx, int sum)
{
	if (idx == primes.size() || sum >= N)
	{
		if (sum == N)
		{
			result++;
		}

		return;
	}

	func(idx + 1, sum + primes[idx]);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	eratosthenes();

	for (int i = 0; i < primes.size(); i++)
	{
		func(i + 1, primes[i]);
	}

	cout << result << "\n";
	
	return 0;
}