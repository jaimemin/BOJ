#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 3;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v(MAX);

	for (int i = 0; i < MAX; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < MAX; i++)
	{
		cout << v[i] << " ";
	}
	cout << "\n";

	return 0;
}