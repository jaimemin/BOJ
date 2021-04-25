#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string socialSecurityNumber;
	cin >> socialSecurityNumber;

	string result;

	if (socialSecurityNumber.find('-') == string::npos)
	{
		if (socialSecurityNumber.substr(0, 2) < "20")
		{
			result = "19" + socialSecurityNumber;
		}
		else
		{
			result = "18" + socialSecurityNumber;
		}
	}
	else
	{
		if (socialSecurityNumber.substr(0, 2) <= "20")
		{
			result = "20" + socialSecurityNumber;
		}
		else
		{
			result = "19" + socialSecurityNumber;
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] == '+' || result[i] == '-')
		{
			continue;
		}

		cout << result[i];
	}

	cout << "\n";

	return 0;
}