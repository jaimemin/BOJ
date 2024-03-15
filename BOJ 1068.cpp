#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;

int result;

int N, deletedNode;

vector<int> v[MAX];

bool visited[MAX];

void func(int node)
{
	bool flag = false;

	for (int next : v[node])
	{
		if (next == deletedNode)
		{
			continue;
		}

		flag = true;
		func(next);
	}

	if (!flag)
	{
		result++;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	int root;

	for (int i = 0; i < N; i++)
	{
		int parent;
		cin >> parent;

		if (parent == -1)
		{
			root = i;

			continue;
		}

		v[parent].push_back(i);
	}

	cin >> deletedNode;

	if (deletedNode == root)
	{
		cout << 0 << "\n";

		return 0;
	}

	func(root);

	cout << result << "\n";

	return 0;
}