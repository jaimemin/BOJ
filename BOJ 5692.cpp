#include <iostream>
#include <string>
using namespace std;

int getFactorial(int factorial)
{
	int result = 1;

	for (int i = 1; i <= factorial; i++)
	{
		result *= i;
	}

	return result;
}

int getFactorialResult(string num)
{
	int result = 0;
	int factorial = 1;

	for (int i = num.length() - 1; i >= 0; i--)
	{
		result += (num[i] - '0') * getFactorial(factorial++);
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		string num;
		cin >> num;

		if (num == "0")
		{
			break;
		}

		cout << getFactorialResult(num) << "\n";
	}

	return 0;
}