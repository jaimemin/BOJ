#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testScore;
	cin >> testScore;

	switch (testScore / 10)
	{
	case 10:
	case 9:
		cout << "A\n";

		break;
	case 8:
		cout << "B\n";

		break;
	case 7:
		cout << "C\n";

		break;
	case 6:
		cout << "D\n";

		break;
	default:
		cout << "F\n";
	}

	return 0;
}