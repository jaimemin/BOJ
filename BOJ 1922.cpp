#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000 + 10;
const int ROOT = 1;

typedef struct
{
	int a, b, c;
}State;

bool operator<(State u, State v)
{
	return u.c > v.c;
}

int N;
int M;
int result;
vector<pair<int, int>> v[MAX];
bool visited[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int m = 0; m < M; m++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	priority_queue<State> pq;

	for (pair<int, int> node : v[ROOT])
	{
		pq.push({ ROOT, node.first, node.second });
	}

	visited[ROOT] = true;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;

		while (!pq.empty())
		{
			a = pq.top().a;
			b = pq.top().b;
			c = pq.top().c;
			pq.pop();

			if (visited[b] == false)
			{
				visited[b] = true;

				break;
			}
		}

		result += c;

		for (pair<int, int> next : v[b])
		{
			pq.push({ b, next.first, next.second });
		}
	}

	cout << result << "\n";

	return 0;
}