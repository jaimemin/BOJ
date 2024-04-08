#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;


const int MAX = 100 + 10;

queue<int> q[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;

	vector<int> v(K);

	for (int i = 0; i < K; i++)
	{
		cin >> v[i];

		q[v[i]].push(i);
	}

	int result = 0;
	set<int> connected;

	for (int i = 0; i < K; i++)
	{
		if (connected.find(v[i]) != connected.end())
		{
			q[v[i]].pop();

			continue;
		}

		if (connected.size() == N)
		{
			int target = -1;

			for (int num : connected)
			{
				if (q[num].empty())
				{
					target = num;

					break;
				}

				if (target == -1)
				{
					target = num;
				}
				else if (q[num].front() > q[target].front())
				{
					target = num;
				}
			}

			connected.erase(target);
			result++;
		}

		connected.insert(v[i]);
		q[v[i]].pop();
	}

	cout << result << "\n";

	return 0;
}