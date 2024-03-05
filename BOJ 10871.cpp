#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, X;
	cin >> N >> X;

	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (num < X)
		{
			v.push_back(num);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];

		if (i != v.size() - 1)
		{
			cout << " ";
		}
	}

	cout << "\n";

	return 0;
}