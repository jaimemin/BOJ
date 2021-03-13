#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 3;

void printResult(int a, int b, int c)
{
	// Á¤»ï°¢Çü
	if (a == b && b == c && c == a)
	{
		cout << 2 << "\n";

		return;
	}

	// Á÷°¢ »ï°¢Çü
	if (c*c == a * a + b * b)
	{
		cout << 1 << "\n";

		return;
	}

	cout << 0 << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int triangleLengths[MAX];
	
	for (int i = 0; i < MAX; i++)
	{
		cin >> triangleLengths[i];
	}

	sort(triangleLengths, triangleLengths + MAX);

	printResult(triangleLengths[0], triangleLengths[1], triangleLengths[2]);

	return 0;
}