#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int INF = 987654321;

const int MAX = 3;

int result = INF;

vector<int> scvs(MAX);

set<pair<vector<int>, int>> visited;

bool allDestroyed(vector<int> &scvs)
{
	for (int i = 0; i < MAX; i++)
	{
		if (scvs[i])
		{
			return false;
		}
	}

	return true;
}

void func(int cnt, vector<int> scvs)
{
	if (allDestroyed(scvs))
	{
		result = min(result, cnt);

		return;
	}

	vector<int> multalisk;
	multalisk.push_back(1);
	multalisk.push_back(3);
	multalisk.push_back(9);
	visited.insert({ scvs, cnt });

	do
	{
		vector<int> copyScvs(MAX);

		for (int i = 0; i < MAX; i++)
		{
			copyScvs[i] = scvs[i];
			scvs[i] = max(scvs[i] - multalisk[i], 0);
		}

		if (visited.find({ scvs, cnt + 1 }) == visited.end())
		{
			func(cnt + 1, scvs);
		}

		for (int i = 0; i < MAX; i++)
		{
			scvs[i] = copyScvs[i];
		}
	} while (next_permutation(multalisk.begin(), multalisk.end()));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> scvs[i];
	}

	func(0, scvs);

	cout << result << "\n";

	return 0;
}