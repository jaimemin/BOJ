#include <iostream>
#include <string>
using namespace std;

bool verify(string input, int startIdx, int endIdx)
{
	if (startIdx >= endIdx)
	{
		return true;
	}

	int left = startIdx;
	int right = endIdx;

	while (left < right)
	{
		if (input[left++] == input[right--])
		{
			return false;
		}
	}

	return verify(input, startIdx, right - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		string input;
		cin >> input;

		if (input.length() % 2 == 0)
		{
			cout << "NO\n";

			continue;
		}

		cout << (verify(input, 0, input.length() - 1) ? "YES\n" : "NO\n");
	}

	return 0;
}