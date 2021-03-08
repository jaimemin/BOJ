#include <iostream>
using namespace std;

const int MINUTE = 60;
const int MAX_HOUR = 24;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;

	B += C;

	while (B >= MINUTE)
	{
		B -= MINUTE;

		if (++A == MAX_HOUR)
		{
			A = 0;
		}
	}

	cout << A << " " << B << "\n";

	return 0;
}