#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int A, B;
		cin >> A >> B;

		cout << A + B << "\n";
	}

	return 0;
}