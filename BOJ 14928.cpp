#include <iostream>
#include <string>
using namespace std;

const int MOD = 20000303;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;

	int result = 0;

	for (int i = 0; i < s.length(); i++)
	{
		int digit = s[i] - '0';

		// �������� ���ϴ� ������ �����غ���
		result = ((result * 10) % MOD + digit) % MOD;
	}

	cout << result << "\n";

	return 0;
}