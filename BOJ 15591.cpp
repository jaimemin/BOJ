#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX = 5e3 + 5;

typedef struct
{
	int similarity;
	int u, v;
} Edge;

bool operator<(const Edge& a, const Edge& b)
{
	return a.similarity > b.similarity;
}

int N, Q;

int parent[MAX];

int ranks[MAX];

int find(int n)
{
	if (n == parent[n])
	{
		return n;
	}

	return parent[n] = find(parent[n]);
}

void merge(int u, int v)
{
	int rootU = find(u);
	int rootV = find(v);

	if (rootU != rootV)
	{
		if (ranks[rootU] > ranks[rootV])
		{
			parent[rootV] = rootU;
		}
		else if (ranks[rootU] < ranks[rootV])
		{
			parent[rootU] = rootV;
		}
		else
		{
			parent[rootV] = rootU;

			ranks[rootU]++;
		}
	}
}

void init()
{
	for (int i = 0; i < MAX; i++)
	{
		parent[i] = i;
		ranks[i] = 1;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;

	init();
	vector<Edge> edges(N - 1);

	for (int i = 0; i < N - 1; i++)
	{
		int p, q, r;
		cin >> p >> q >> r;

		edges[i] = { r, p - 1, q - 1 };
	}

	vector<pair<int, pair<int, int>>> queries(Q);

	for (int i = 0; i < Q; i++)
	{
		int k, v;
		cin >> k >> v;

		queries[i] = { k, {v - 1, i} };
	}

	sort(edges.begin(), edges.end());
	sort(queries.begin(), queries.end(), greater<pair<int, pair<int, int>>>());

	vector<int> answer(Q);
	int idx = 0;

	for (int i = 0; i < Q; i++)
	{
		int k = queries[i].first;
		int v = queries[i].second.first;
		int queryIdx = queries[i].second.second;

		while (idx < edges.size() && edges[idx].similarity >= k)
		{
			merge(edges[idx].u, edges[idx].v);

			idx++;
		}

		int cnt = 0;

		for (int j = 0; j < N; j++)
		{
			if (find(j) == find(v) && j != v)
			{
				cnt++;
			}
		}

		answer[queryIdx] = cnt;
	}

	for (int i = 0; i < Q; i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}
