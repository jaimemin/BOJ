#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000 + 10;

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
	int N;
	cin >> N;

	eratosthenes();

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;

		answer += (minFactor[n] == n);
	}

	cout << answer << "\n";

	return 0;
}