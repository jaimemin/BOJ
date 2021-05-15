#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getCarryCnt(int a, int b)
{
	string num = to_string(a);
	string num2 = to_string(b);

	reverse(num.begin(), num.end());
	reverse(num2.begin(), num2.end());

	int carryCnt = 0;
	bool carry = false;

	for (int i = 0; i < min(num.size(), num2.size()); i++)
	{
		int sum = (num[i] - '0') + (num2[i] - '0') + carry;

		if (sum >= 10)
		{
			carry = true;
			carryCnt++;
		}
		else
		{
			carry = false;
		}
	}

	for (int i = (num.size() > num2.size() ? num2.size() : num.size()); i < (num.size() > num2.size() ? num.size() : num2.size()); i++)
	{
		int sum = num.size() > num2.size() ? num[i] : num2[i] + carry;

		if (sum >= 10)
		{
			carry = true;
			carryCnt++;
		}
		else
		{
			carry = false;
		}
	}

	return carryCnt;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
		{
			break;
		}

		cout << getCarryCnt(a, b) << "\n";
	}

	return 0;
}