#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2;

enum Girls {
	Bec = 0,
	Cas
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int day = 1; ;day++)
	{
		int n, d;
		cin >> n >> d;

		if (n == 0 && d == 0)
		{
			break;
		}

		cout << "Scenario " << day << "\n";

		vector<int> wardrobes[MAX];

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				wardrobes[i].push_back(j);
			}

			int r;
			cin >> r;

			if (r == 0)
			{
				continue;
			}

			if (i == Bec)
			{
				wardrobes[i].erase(wardrobes[i].begin() + r - 1);
			}
			else
			{
				wardrobes[i].erase(wardrobes[i].end() - r);
			}
		}

		int becSize = wardrobes[Bec].size();
		int casSize = wardrobes[Cas].size();

		for (int i = 1; i <= d; i++)
		{
			int bec, cas;
			cin >> bec >> cas;

			cout << "Day " << i << " ";

			if (wardrobes[Bec][bec - 1] != wardrobes[Cas][casSize - cas])
			{
				cout << "OK\n";
			}
			else
			{
				cout << "ALERT\n";
			}
		}
	}

	return 0;
}