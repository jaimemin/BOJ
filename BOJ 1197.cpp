#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1e4 + 100;

typedef struct
{
	int A, B, C;
}State;

bool operator<(State u, State v)
{
	return u.C > v.C;
}

int V, E;
int result;
int parent[MAX];

int findParent(int x)
{
	if (parent[x] == x)
	{
		return x;
	}

	return parent[x] = findParent(parent[x]);
}

void merge(int a, int b)
{
	a = findParent(a);
	b = findParent(b);

	parent[a] = b;
}

void initParent()
{
	for (int v = 1; v <= V; v++)
	{
		parent[v] = v;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E;

	initParent();

	priority_queue<State> pq;

	for (int e = 0; e < E; e++)
	{
		State temp;
		cin >> temp.A >> temp.B >> temp.C;

		pq.push(temp);
	}

	for (int e = 0; e < E; e++)
	{
		int A = pq.top().A;
		int B = pq.top().B;
		int C = pq.top().C;
		pq.pop();

		if (findParent(A) == findParent(B))
		{
			continue;
		}

		merge(A, B);
		result += C;
	}

	cout << result << "\n";

	return 0;
}