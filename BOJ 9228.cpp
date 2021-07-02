#include <iostream>
#include <string>
using namespace std;

const int MOD = 10;
const int DIVIDE = 11;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		string s;
		cin >> s;

		if (s == "#")
		{
			break;
		}

		long long num = stoll(s);
		long long sum = 0;

		int mul = 2;

		while (num)
		{
			sum += (mul++ * (num % MOD));

			num /= MOD;
		}

		sum %= DIVIDE;

		int remainder = 11 - sum;
		string result = s;
		bool isRejected = false;

		switch (remainder)
		{
		case 10:
			isRejected = true;

			break;
		case 11:
			result = '0';

			break;
		default:
			result = (remainder + '0');

			break;
		}
		
		if (isRejected)
		{
			cout << s << " -> Rejected\n";
		}
		else
		{
			cout << s << " -> " << result << "\n";
		}
	}

	return 0;
}