#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int aSum = 0, bSum = 0;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		if (a > b)
		{
			aSum += (a + b);
		}
		else if (a < b)
		{
			bSum += (a + b);
		}
		else
		{
			aSum += a;
			bSum += b;
		}
	}

	cout << aSum << " " << bSum << "\n";

	return 0;
}