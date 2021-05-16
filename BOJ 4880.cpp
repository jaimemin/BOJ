#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int a1, a2, a3;
		cin >> a1 >> a2 >> a3;

		if (a1 == 0 && a2 == 0 && a3 == 0)
		{
			break;
		}

		bool isAP = a2 - a1 == a3 - a2;
		bool isGP = a2 * a2 == a1 * a3;

		if (isAP)
		{
			cout << "AP " << a3 + (a3 - a2) << "\n";
		}
		
		if (isGP)
		{
			cout << "GP " << a3 * (a3 / a2) << "\n";
		}
	}

	return 0;
}