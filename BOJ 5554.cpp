#include <iostream>
using namespace std;

const int MAX = 4;
const int MINUTE_TO_SECOND = 60;

void printTimeFormat(int seconds)
{
	int minute = 0;

	while (seconds / MINUTE_TO_SECOND)
	{
		seconds -= MINUTE_TO_SECOND;

		minute++;
	}

	cout << minute << "\n";
	cout << seconds << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int seconds = 0;

	for (int i = 0; i < MAX; i++)
	{
		int second;
		cin >> second;

		seconds += second;
	}

	printTimeFormat(seconds);

	return 0;
}