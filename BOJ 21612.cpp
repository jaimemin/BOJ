#include <iostream>
using namespace std;

const int SEA_LEVEL = 100;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int B;
	cin >> B;

	int P = 5 * B - 400;
	
	cout << P << "\n";

	if (P < SEA_LEVEL)
	{
		cout << 1 << '\n';
	} 
	else if (P > SEA_LEVEL)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << 0 << "\n";
	}

	return 0;
	
}