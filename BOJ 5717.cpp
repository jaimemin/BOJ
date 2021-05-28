#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int M, F;
		cin >> M >> F;

		if (M == 0 && F == 0)
		{
			break;
		}

		int result = M + F;

		cout << result << "\n";
	}

	return 0;
}