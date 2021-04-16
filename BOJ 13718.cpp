#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, K, X;
	cin >> N >> M >> K >> X;

	string s;
	cin >> s;

	vector<string> candidates(M);
	vector<char> missingLetters;

	for (int i = 0; i < M; i++)
	{
		cin >> candidates[i];

		sort(candidates[i].begin(), candidates[i].end());
		missingLetters.push_back(candidates[i][0]);
	}

	X--;

	for (int i = M - 1; X && i >= 0; i--)
	{
		int idx = X % K;

		missingLetters[i] = candidates[i][idx];

		X /= K;
	}

	int missingLetterIdx = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '#')
		{
			cout << missingLetters[missingLetterIdx++];

			continue;
		}

		cout << s[i];
	}

	cout << "\n";

	return 0;
}