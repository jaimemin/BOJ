#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int MAX = 15;

const int INF = 987654321;

int N;

int cost = INF;

map<int, set<vector<int>>> cost2vector;

int minNutritions[4];

int nutritions[MAX][5];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < 4; i++)
	{
		cin >> minNutritions[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> nutritions[i][j];
		}
	}

	for (int i = 1; i < (1 << N); i++)
	{
		vector<int> v;

		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				v.push_back(j);
			}
		}

		vector<int> temp(5, 0);

		for (int idx : v)
		{
			for (int k = 0; k < 5; k++)
			{
				temp[k] += nutritions[idx][k];
			}
		}

		bool flag = true;

		for (int k = 0; k < 4; k++)
		{
			if (minNutritions[k] > temp[k])
			{
				flag = false;

				break;
			}
		}

		if (!flag || cost < temp[4])
		{
			continue;
		}

		if (cost < temp[4])
		{
			continue;
		}

		cost = temp[4];
		cost2vector[cost].insert(v);
	}

	if (cost == INF)
	{
		cout << -1 << "\n";

		return 0;
	}

	cout << cost << "\n";

	for (vector<int> v : cost2vector[cost])
	{
		for (int idx : v)
		{
			cout << idx + 1 << " ";
		}

		break;
	}

	cout << "\n";

	return 0;
}