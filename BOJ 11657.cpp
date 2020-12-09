#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ROOT = 1;
const int MAX = 500 + 50;
const int BUS_MAX = 6000 + 60;
const int INF = 987654321;

typedef struct
{
	int A, B, C;
}City;

int N, M;
long long dist[MAX];
City cities[BUS_MAX];

void init(void)
{
	for (int i = 0; i < MAX; i++)
	{
		dist[i] = INF;
	}
}

// BellmanFord
void printDistance(void)
{
	bool cycle = false;
	dist[ROOT] = 0;

	for (int n = 1; n <= N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			int A = cities[m].A;
			int B = cities[m].B;
			int C = cities[m].C;

			if (dist[A] == INF)
			{
				continue;
			}

			if (dist[B] <= dist[A] + C)
			{
				continue;
			}

			dist[B] = dist[A] + C;

			if (n == N)
			{
				cycle = true;
			}
		}
	}

	if (cycle)
	{
		cout << -1 << "\n";

		return;
	}

	for (int n = 2; n <= N; n++)
	{
		if (dist[n] == INF)
		{
			cout << -1 << "\n";

			continue;
		}

		cout << dist[n] << "\n";
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int m = 0; m < M; m++)
	{
		City temp;
		cin >> temp.A >> temp.B >> temp.C;

		cities[m] = temp;
	}

	init();

	printDistance();

	return 0;
}