#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1 << 10;

int K;

bool visited[MAX];

int tree[MAX];

vector<int> v[10 + 1];

void func(int left, int right, int height)
{
	if (left > right)
	{
		return;
	}

	if (left == right)
	{
		v[height].push_back(tree[left]);

		return;
	}

	int mid = (left + right) / 2;
	
	v[height].push_back(tree[mid]);
	func(left, mid - 1, height + 1);
	func(mid + 1, right, height + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> K;

	int right = (1 << K) - 1;

	for (int i = 0; i < right; i++)
	{
		cin >> tree[i];
	}

	func(0, right, 0);

	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j];

			if (j != v[i].size())
			{
				cout << " ";
			}
		}

		cout << "\n";
	}

	return 0;
}