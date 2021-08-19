#include <iostream>
using namespace std;

const int MAX = 210;
const int MOD = 8;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int K, N;
	cin >> K >> N;

	int total = 0;

	for (int n = 0; n < N; n++)
	{
		int T;
		char Z;
		cin >> T >> Z;

		total += T;

		if (total >= MAX)
		{
			break;
		}

		if (Z == 'T')
		{
			K++;
		}

		if (K > MOD)
		{
			K %= MOD;
		}
	}

	cout << K << "\n";

	return 0;
}