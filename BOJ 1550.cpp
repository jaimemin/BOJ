#include <iostream>
#include <string>
using namespace std;

const int BASE = 16;

int power(int num, int idx)
{
	int result = num;

	for (int i = 0; i < idx; i++)
	{
		result *= BASE;
	}

	return result;
}

int convertHexToDec(char c)
{
	if ('A' <= c && 'F' >= c) {
		return c - 'A' + 10;
	}

	return c - '0';
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string hexNumber;
	cin >> hexNumber;

	int result = 0;

	for (int i = 0; i < hexNumber.length(); i++)
	{
		int num = convertHexToDec(hexNumber[i]);

		result += power(num, hexNumber.length() - (i + 1));
	}

	cout << result << "\n";

	return 0;
}