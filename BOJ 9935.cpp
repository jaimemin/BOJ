#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, bomb;
	cin >> s >> bomb;

	string result;

	for (char c : s)
	{
		result += c;

		if (result.length() >= bomb.length()
			&& result.substr(result.length() - bomb.length(), bomb.length()) == bomb)
		{
			result = result.erase(result.length() - bomb.length(), result.length());
		}
	}

	cout << (result == "" ? "FRULA" : result) << "\n";

	return 0;
}