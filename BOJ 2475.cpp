#include <iostream>
using namespace std;

const int MAX = 5;
const int MOD = 10;

int getSquare(int number)
{
	return number * number;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int result = 0;

	for (int i = 0; i < MAX; i++)
	{
		int num;
		cin >> num;

		result += getSquare(num);
	}

	cout << result % MOD << "\n";

}