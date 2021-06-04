#include <iostream>
using namespace std;

int getDuration(int year, int month, int day)
{
	int result = 0;

	result += (year - 1) * 195;
	result += (year - 1) / 3 * 5; //every three month

	if (year % 3 != 0)
	{
		result -= (month - 1) / 2;
	}

	result += (month - 1) * 20;
	result += day;

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int initialDuration = getDuration(1000, 1, 1);

	for (int i = 0; i < n; i++)
	{
		int Y, M, D;
		cin >> Y >> M >> D;

		int result = initialDuration - getDuration(Y, M, D);

		cout << result << "\n";
	}

	return 0;
}