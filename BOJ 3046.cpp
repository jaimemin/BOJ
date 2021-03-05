#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int R1, S;
	cin >> R1 >> S;

	int R2 = S * 2 - R1;

	cout << R2 << "\n";

	return 0;
}