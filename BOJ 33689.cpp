#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;

	int answer = 0;

	while (N--)
	{
		string s;
		cin >> s;

		answer += (s[0] == 'c' || s[0] == 'C');
	}

	cout << answer << "\n";

	return 0;
}