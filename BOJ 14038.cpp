#include <iostream>
using namespace std;

const int MAX = 6;

void printResult(int win)
{
	switch (win)
	{
	case 6:
	case 5:
		cout << 1 << "\n";

		break;
	case 4:
	case 3:
		cout << 2 << "\n";

		break;
	case 2:
	case 1:
		cout << 3 << "\n";

		break;
	default:
		cout << -1 << "\n";
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int win = 0;

	for (int i = 0; i < MAX; i++)
	{
		char result;
		cin >> result;

		win += (result == 'W');
	}

	printResult(win);

	return 0;
}