#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s;
	cin >> s;

	char prev = s[0];
	int result = 10;

	for (int i = 1; i < s.length(); i++)
	{
		result += ((prev == s[i]) ? 5 : 10);

		prev = s[i];
	}

	cout << result << "\n";

	return 0;
}