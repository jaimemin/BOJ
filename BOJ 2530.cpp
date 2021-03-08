#include <iostream>
using namespace std;

const int SECOND = 60;
const int MINUTE = 60;
const int MAX_HOUR = 24;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	C += D;

	while (C >= SECOND)
	{
		C -= SECOND;

		if (++B >= MINUTE)
		{
			B -= 60;

			if (++A >= MAX_HOUR)
			{
				A = 0;
			}
		}
	}

	cout << A << " " << B << " " << C << "\n";

	return 0;
}