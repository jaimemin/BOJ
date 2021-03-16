#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long pow(int p)
{
	int result = 1;

	for (int i = 0; i < p; i++)
	{
		result *= 2;
	}

	return result;
}

string convertDecToBinary(long long dec)
{
	string binary = "";

	while (dec)
	{
		binary += dec % 2 + '0';

		dec /= 2;
	}

	reverse(binary.begin(), binary.end());

	return binary;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string B1, B2;
	cin >> B1 >> B2;

	long long B1Dec = 0, B2Dec = 0;
	int B1Length = B1.length(), B2Length = B2.length();

	for (int i = 0; i < B1Length; i++)
	{
		B1Dec += B1[i] == '1' ? pow(B1Length - (i + 1)) : 0;
	}

	for (int i = 0; i < B2Length; i++)
	{
		B2Dec += B2[i] == '1' ? pow(B2Length - (i + 1)) : 0;
	}

	string result = convertDecToBinary(B1Dec * B2Dec);

	cout << result << "\n";

	return 0;
}