#include <iostream>
#include <string>
using namespace std;

long long calc(long long temp, long long cur, string op)
{
	if (op == "+")
	{
		return temp + cur;
	}
	else if (op == "-")
	{
		return temp - cur;
	}
	else if (op == "*")
	{
		return temp * cur;
	}
	else
	{
		return temp / cur;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long result = 0;
	string op;

	for (int i = 0; ; i++)
	{
		string s;
		cin >> s;

		if (s == "=")
		{
			break;
		}

		if (i == 0)
		{
			result = stoll(s);
		}
		else if (i % 2)
		{
			op = s;
		}
		else
		{
			result = calc(result, stoll(s), op);
		}
	}

	cout << result << "\n";

	return 0;
}