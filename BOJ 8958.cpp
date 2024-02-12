#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--)
	{
		string s;
		cin >> s;

		int consecutive = 1;
		int result = 0;

		for (char c : s)
		{
			if (c == 'X')
			{
				consecutive = 1;

				continue;
			}

			result += consecutive++;
		}

		cout << result << "\n";
	}

	return 0;
}