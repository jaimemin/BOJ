#include <iostream>
using namespace std;

const int FOURTY_FIVE_MINUTES = 45;
const int HOUR_TO_MINUTE = 60;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int H, M;
	cin >> H >> M;

	M -= FOURTY_FIVE_MINUTES;

	if (M < 0)
	{
		M += HOUR_TO_MINUTE;

		if (--H == -1)
		{
			H = 23;
		}
	}

	cout << H << " " << M << "\n";

	return 0;
}