#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
		{
			break;
		}

		if (a%b == 0)
		{
			cout << "multiple\n";

			continue;
		}

		if (b%a == 0)
		{
			cout << "factor\n";
			
			continue;
		}

		cout << "neither\n";
	}

	return 0;
}