#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		int N;
		cin >> N;

		if (N == 0)
		{
			break;
		}

		vector<int> v(N);

		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}

		int cnt = 0;

		for (int i = 1; i < N - 1; i++)
		{
			if (v[i] > v[i - 1] && v[i] > v[i + 1])
			{
				cnt++;
			}
		}
		
		cout << cnt << "\n";
	}

	return 0;
}