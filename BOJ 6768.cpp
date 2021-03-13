#include <iostream>
using namespace std;

int getCombination(int J)
{
	return (J - 1) * (J - 2) * (J - 3) / 6; // (J-1)C3
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int J;
	cin >> J;

	cout << getCombination(J) << "\n";

	return 0;
}