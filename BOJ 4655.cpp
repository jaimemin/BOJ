#include <iostream>
using namespace std;

int getCardCnt(double c)
{
	double sum = 0.00;

	for (int i = 1; ;i++)
	{
		sum += (1 / (double)(i + 1));

		if (sum >= c)
		{
			return i;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		double c;
		cin >> c;

		if (c == 0.00)
		{
			break;
		}

		cout << getCardCnt(c) << " card(s)\n";
	}

	return 0;
}