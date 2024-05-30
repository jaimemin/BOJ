#include <iostream>
#include <string>
using namespace std;

const int INF = 987654321;

const int MAX = 2500 + 25;

string s;

bool isPalindrome[MAX][MAX];

int cache[MAX];

int func(int idx)
{
	if (idx == s.length())
	{
		return 0;
	}

	int& result = cache[idx];

	if (result != INF)
	{
		return result;
	}

	for (int palindromeSize = 1; idx + palindromeSize <= s.length(); palindromeSize++)
	{
		if (isPalindrome[idx][palindromeSize])
		{
			result = min(result, 1 + func(idx + palindromeSize));
		}
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		isPalindrome[i][1] = 1;
	}

	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			isPalindrome[i][2] = 1;
		}
	}

	for (int palindromeSize = 3; palindromeSize <= s.length(); palindromeSize++)
	{
		for (int j = 0; j + palindromeSize <= s.length(); j++)
		{
			if (s[j] == s[j + palindromeSize - 1]
				&& isPalindrome[j + 1][palindromeSize - 2])
			{
				isPalindrome[j][palindromeSize] = 1;
			}
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		cache[i] = INF;
	}

	cout << func(0) << "\n";

	return 0;
}