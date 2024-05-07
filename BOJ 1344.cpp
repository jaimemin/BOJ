#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 18 + 1;

double A, B;

int minFactor[MAX];

double cache[MAX][MAX][MAX];

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
}

double func(int idx, int a, int b)
{
	if (idx == 18)
	{
		if (minFactor[a] == a 
			|| minFactor[b] == b)
		{
			return 1.0;
		}

		return 0.0;
	}

	double& result = cache[idx][a][b];

	if (result > -0.5)
	{
		return result;
	}

	result = 0.0;
	result += A * B * func(idx + 1, a + 1, b + 1);
	result += A * (1 - B) * func(idx + 1, a + 1, b);
	result += (1 - A) * B * func(idx + 1, a, b + 1);
	result += (1 - A) * (1 - B) * func(idx + 1, a, b);

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B;
	
	A /= 100;
	B /= 100;

	eratosthenes();

	memset(cache, -1, sizeof(cache));
	printf("%.6lf\n", func(0, 0, 0));

	return 0;
}