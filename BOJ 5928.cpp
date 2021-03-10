#include <iostream>
using namespace std;

const int ELEVEN = 11;
const int MAX_MINUTE = 60;
const int MAX_HOUR = 24;

bool isBessieLate(int D, int H, int M)
{
	if (D > ELEVEN)
	{
		return false;
	}

	if (H < ELEVEN)
	{
		return true;
	}

	if (H == ELEVEN && M < ELEVEN)
	{
		return true;
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int D, H, M;
	cin >> D >> H >> M;

	if (isBessieLate(D, H, M))
	{
		cout << -1 << "\n";

		return 0;
	}

	int minute = M - ELEVEN;
	int hour = H - ELEVEN;
	int day = D - ELEVEN;

	if (minute < 0)
	{
		minute += MAX_MINUTE;
		hour--;
	}

	if (hour < 0)
	{
		hour += MAX_HOUR;
		day--;
	}

	int result = day * MAX_HOUR * MAX_MINUTE + hour * MAX_MINUTE + minute;

	cout << result << "\n";

	return 0;
}