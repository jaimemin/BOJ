#include <iostream>
using namespace std;

bool isValid(int binaryNum, int checkBit)
{
	int cnt = 0;

	while (binaryNum)
	{
		if (binaryNum % 2)
		{
			cnt++;
		}

		binaryNum /= 2;
	}

	return (cnt % 2) == checkBit;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int binaryNum, checkBit;
		cin >> binaryNum >> checkBit;

		cout << (isValid(binaryNum, checkBit) ? "Valid\n" : "Corrupt\n");
	}

	return 0;
}