#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 10;

int k;

long long maxS = 0;

long long minS = LLONG_MAX;

char arr[MAX];

bool visited[MAX];

void func(string s)
{
	if (s.length() == k + 1)
	{
		for (int i = 0; i < k; i++)
		{
			if (arr[i] == '<')
			{
				if (s[i] - '0' > s[i + 1] - '0')
				{
					return;
				}
			}
			else
			{
				if (s[i] - '0' < s[i + 1] - '0')
				{
					return;
				}
			}
		}

		maxS = max(maxS, stoll(s));
		minS = min(minS, stoll(s));

		return;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (visited[i])
		{
			continue;
		}

		visited[i] = true;
		func(s + to_string(i));
		visited[i] = false;
	}
}

string convert(long long num)
{
	string result = to_string(num);
	
	return result.length() == k ? "0" + result : result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	func("");

	cout << convert(maxS) << "\n" << convert(minS) << "\n";

	return 0;
}