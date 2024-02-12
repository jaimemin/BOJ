#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		vector<pair<int, string>> v;

		for (int i = 0; i < N; i++)
		{
			string S;
			int L;
			cin >> S >> L;

			v.push_back({ L, S });
		}

		sort(v.begin(), v.end());

		cout << v[N - 1].second << "\n";
	}

	return 0;
}