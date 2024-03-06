#include <iostream>
#include <string>
using namespace std;

bool doesPatternMatch(string s, string prefix, string suffix)
{
	return s.length() >= suffix.length() 
		&& s.substr(0, prefix.length()) == prefix 
		&& s.substr(s.length() - suffix.length(), suffix.length()) == suffix;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	string pattern;
	cin >> pattern;

	string prefix, suffix;
	bool isPrefix = true;

	for (char c : pattern)
	{
		if (c == '*')
		{
			isPrefix = false;
			
			continue;
		}

		isPrefix ? prefix += c : suffix += c;
	}

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		if (prefix.length() + suffix.length() > s.length())
		{
			cout << "NE\n";

			continue;
		}

		if (doesPatternMatch(s, prefix, suffix))
		{
			cout << "DA\n";
		}
		else
		{
			cout << "NE\n";
		}
	}

	return 0;
}