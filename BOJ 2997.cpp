#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v(3);

	for (int i = 0; i < 3; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int diff = v[1] - v[0];
	int diff2 = v[2] - v[1];

	if (diff == diff2)
	{
		cout << v[2] + diff << "\n";
	}
	else if (diff > diff2)
	{
		cout << v[0] + diff2 << "\n";
	}
	else
	{
		cout << v[1] + diff << "\n";
	}

	return 0;
}