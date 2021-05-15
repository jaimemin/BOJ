#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (1)
	{
		int n;
		cin >> n;

		if (n == -1)
		{
			break;
		}

		int pastT = 0;
		int miles = 0;

		for (int i = 0; i < n; i++)
		{
			int s, t;
			cin >> s >> t;

			miles += s * (t - pastT);

			pastT = t;
		}

		cout << miles << " miles\n";
	}

	return 0;
}