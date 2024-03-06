#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	getline(cin, s);

	for (char c : s)
	{
		if (c >= 'A' && c <= 'Z')
		{
			cout << char('A' + (c - 'A' + 13) % 26);
		}
		else if (c >= 'a' && c <= 'z')
		{
			cout << char('a' + (c - 'a' + 13) % 26);
		}
		else
		{
			cout << c;
		}
	}
	
	return 0;
}