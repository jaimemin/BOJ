#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int result;

	if (N % 2)
	{
		cout << "Either\n";
	}
	else
	{
		if ((N / 2) % 2)
		{
			cout << "Odd\n";
		}
		else
		{
			cout << "Even\n";
		}
	}

	return 0;
}