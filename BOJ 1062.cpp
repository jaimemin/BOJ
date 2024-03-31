#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 50;

const int ALPHABET_MAX = 26;

const int MIN_ALPHABET_CNT = 5; // a, c, i, n, t

string words[MAX];

bool visited[MAX][ALPHABET_MAX];

bool containsRequiredAlphabets(int bit)
{
	return ((1 << 0) & bit)
		&& ((1 << 2) & bit)
		&& ((1 << 8) & bit)
		&& ((1 << 13) & bit)
		&& ((1 << 19) & bit);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> words[i];

		for (char c : words[i])
		{
			visited[i][c - 'a'] = true;
		}
	}

	if (K < MIN_ALPHABET_CNT)
	{
		cout << 0 << "\n";

		return 0;
	}

	int result = 0;

	for (int bit = 1; bit < (1 << ALPHABET_MAX); bit++)
	{
		if (!containsRequiredAlphabets(bit))
		{
			continue;
		}

		int teached = 0;

		for (int c = 0; c < ALPHABET_MAX; c++)
		{
			if ((1 << c) & bit)
			{
				teached++;
			}
		}

		if (teached != K)
		{
			continue;
		}

		int cnt = 0;

		for (int i = 0; i < N; i++)
		{
			bool flag = true;

			for (int c = 0; c < ALPHABET_MAX; c++)
			{
				if (!visited[i][c])
				{
					continue;
				}

				if (!(bit & (1 << c)))
				{
					flag = false;

					break;
				}
			}

			cnt += flag;
		}

		result = max(result, cnt);
	}

	cout << result << "\n";

	return 0;
}