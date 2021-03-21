#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;

	int A = stoi(s.length() >= 3 && s[1] == '0' ? s.substr(0, 2) : s.substr(0, 1));
	int B = stoi(A == 10 ? s.substr(2) : s.substr(1));
	int result = A + B;

	cout << result << "\n";

	return 0;
}