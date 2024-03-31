#include <iostream>
#include <string>
using namespace std;

string s;

bool canMake = false;

void func(int idx)
{
	if (idx == s.length())
	{
		canMake = true;

		return;
	}

	if (s.substr(idx, 2) == "pi")
	{
		func(idx + 2);
	}

	if (s.substr(idx, 2) == "ka")
	{
		func(idx + 2);
	}

	if (s.substr(idx, 3) == "chu")
	{
		func(idx + 3);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;

	func(0);

	cout << (canMake ? "YES\n" : "NO\n");

	return 0;
}