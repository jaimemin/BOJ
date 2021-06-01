#include <iostream>
using namespace std;

int main(void)
{
	int holeNum = 1;

	while (1)
	{
		int p, s;
		cin >> p >> s;

		if (p == 0 && s == 0)
		{
			break;
		}

		printf("Hole #%d\n", holeNum++);

		if (s == 1)
		{
			cout << "Hole-in-one.\n\n";

			continue;
		}

		switch (s - p)
		{
		case -2:
			cout << "Eagle.\n\n";

			break;
		case -1:
			cout << "Birdie.\n\n";

			break;
		case 0:
			cout << "Par.\n\n";

			break;
		case 1:
			cout << "Bogey.\n\n";

			break;
		default:
			if (s - p < -2)
			{
				cout << "Double eagle.\n\n";
			}
			else
			{
				cout << "Double Bogey.\n\n";
			}
		}
	}

	return 0;
}