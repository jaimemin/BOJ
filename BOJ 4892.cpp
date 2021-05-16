#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int idx = 1; ; idx++)
	{
		int n0;
		cin >> n0;

		if (n0 == 0)
		{
			break;
		}

		int n1 = 3 * n0;
		int n2;

		cout << idx << ". ";

		if (n1 % 2)
		{
			cout << "odd ";
			n2 = (n1 + 1) / 2;
		}
		else
		{
			cout << "even ";
			n2 = n1 / 2;
		}

		int n3 = 3 * n2;
		int n4 = n3 / 9;

		cout << n4 << "\n";
	}

	return 0;
}