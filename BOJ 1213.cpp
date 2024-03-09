#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 26;

int alphabets[MAX];

int main(void)
{
	string s;
	cin >> s;

	for (char c : s)
	{
		alphabets[c - 'A']++;
	}

	int oddCnt = 0;
	int oddIdx = -1;

	for (int i = 0; i < MAX; i++)
	{
		oddCnt += (alphabets[i] % 2);
		
		if (alphabets[i] % 2)
		{
			oddIdx = i;
		}
	}

	if (oddCnt >= 2)
	{
		cout << "I'm Sorry Hansoo\n";

		return 0;
	}

	string temp;

	for (int i = 0; i < MAX; i++)
	{
		if (alphabets[i] == 0)
		{
			continue;
		}

		char c = char('A' + i);

		for (int j = 0; j < alphabets[i] / 2; j++)
		{
			temp += c;
		}
	}

	string prefix = temp;
	reverse(temp.begin(), temp.end());

	string result = prefix;

	if (oddIdx >= 0)
	{
		result += char('A' + oddIdx);
	}

	result += temp;

	cout << result << "\n";

	return 0;
}