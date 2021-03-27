#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (true)
	{
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
		{
			break;
		}

		int groupNum = max((a - b) / 2 - (a - b) % 2, 0);
		int groupOfThree = a - b <= 1 ? 0 : (a - b) % 2;

		cout << groupNum << " " << groupOfThree << "\n";
	}

	return 0;
}