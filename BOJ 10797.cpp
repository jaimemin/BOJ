#include <iostream>
using namespace std;

const int MAX = 5;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int day;
	cin >> day;

	int result = 0;

	for (int i = 0; i < MAX; i++)
	{
		int car;
		cin >> car;

		if (day == car)
		{
			result++;
		}
	}

	cout << result << "\n";
	
	return 0;
}