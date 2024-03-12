#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef struct
{
	int num;
	int initIdx;
	int cnt;
} State;

bool cmp(State& a, State& b)
{
	if (a.cnt > b.cnt)
	{
		return true;
	}

	if (a.cnt == b.cnt)
	{
		if (a.initIdx < b.initIdx)
		{
			return true;
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, C;
	cin >> N >> C;

	map<int, int> num2idx;
	vector<State> v;
	int idx = 0;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (!num2idx.count(num))
		{
			v.push_back({ num, idx, 1 });
			num2idx[num] = idx++;
		}
		else
		{
			v[num2idx[num]].cnt++;
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].cnt; j++)
		{
			cout << v[i].num;

			if (!(i == v.size() - 1 && j == v[i].cnt - 1))
			{
				cout << " ";
			}
		}
	}
	
	cout << "\n";

	return 0;
}