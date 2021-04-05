#include <iostream>
#include <string>
using namespace std;

long long pow(int n)
{
	long long result = 1;

	for (int i = 0; i < n; i++)
	{
		result *= 8;
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		string octopusNumber;
		cin >> octopusNumber;

		if (octopusNumber == "#")
		{
			break;
		}

		long long result = 0;

		for (int i = 0; i < octopusNumber.length(); i++)
		{
			switch (octopusNumber[i])
			{
			case '-':
				break;
			case '\\':
				result += pow(octopusNumber.length() - (i + 1));

				break;
			case '(':
				result += 2 * pow(octopusNumber.length() - (i + 1));

				break;
			case '@':
				result += 3 * pow(octopusNumber.length() - (i + 1));

				break;
			case '?':
				result += 4 * pow(octopusNumber.length() - (i + 1));

				break;
			case '>':
				result += 5 * pow(octopusNumber.length() - (i + 1));

				break;
			case '&':
				result += 6 * pow(octopusNumber.length() - (i + 1));

				break;
			case '%':
				result += 7 * pow(octopusNumber.length() - (i + 1));

				break;
			case '/':
				result -= pow(octopusNumber.length() - (i + 1));

				break;
			}
		}

		cout << result << "\n";
	}

	return 0;
}