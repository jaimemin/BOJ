#include <iostream>
#include <string>
#include <set>
using namespace std;

set<char> vowels;

void init() 
{
	vowels.insert('a');
	vowels.insert('e');
	vowels.insert('i');
	vowels.insert('o');
	vowels.insert('u');
}

bool condition1(string s)
{
	for (char c : s)
	{
		if (vowels.find(c) != vowels.end())
		{
			return true;
		}
	}

	return false;
}

bool condition2(string s)
{
	int consecutiveVowels = 0, consecutiveNonVowels = 0;

	for (char c : s)
	{
		if (vowels.find(c) != vowels.end())
		{
			if (++consecutiveVowels == 3)
			{
				return false;
			}

			consecutiveNonVowels = 0;
		}
		else
		{
			if (++consecutiveNonVowels == 3)
			{
				return false;
			}

			consecutiveVowels = 0;
		}
	}

	return true;
}

bool condition3(string s)
{
	char prev = s[0];

	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == prev && prev != 'e' && prev != 'o')
		{
			return false;
		}

		prev = s[i];
	}

	return true;
}

int main(void)
{
	init();

	while (true)
	{
		string s;
		cin >> s;

		if (s == "end")
		{
			break;
		}

		if (condition1(s) && condition2(s) && condition3(s))
		{
			cout << "<" << s << "> is acceptable.\n";
		}
		else
		{
			cout << "<" << s << "> is not acceptable.\n";
		}
	}

	return 0;
}