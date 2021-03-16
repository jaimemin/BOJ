#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;

	int seconds = 0;

	while (true)
	{
		if (A == B)
		{
			cout << seconds << "\n";

			break;
		}

		if (A < 0)
		{
			seconds += C;
		}
		else if (A == 0)
		{
			seconds += (D + E);
		}
		else
		{
			seconds += E;
		}

		A++;
	}

	return 0;
}