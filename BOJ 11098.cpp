#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	while (n--)
	{
		int p;
		cin >> p;

		vector<pair<int, string>> v;

		for (int i = 0; i < p; i++)
		{
			int C;
			string name;
			cin >> C >> name;

			v.push_back({ C, name });
		}

		sort(v.begin(), v.end());

		cout << v.back().second << "\n";
	}

	return 0;
}