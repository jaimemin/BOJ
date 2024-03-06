#include <iostream>
#include <string>
using namespace std;

const int MAX = 26;

int alphabets[MAX] = { 0, };

int main(void)
{
	string s;
	cin >> s;

	for (char c : s)
	{
		alphabets[c - 'a']++;
	}

	for (int i = 0; i < MAX; i++)
	{
		cout << alphabets[i];

		if (i != MAX - 1)
		{
			cout << " ";
		}
	}

	cout << "\n";

	return 0;
}