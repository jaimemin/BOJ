#include <iostream>
#include <string>
#include <stack>
using namespace std;

const int MAX = 2e5 + 20;

bool correct[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	string s;
	cin >> s;

	stack<int> st;

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];

		if (c == ')')
		{
			if (!st.empty())
			{
				correct[i] = true;
				correct[st.top()] = true;

				st.pop();
			}
	
			continue;
		}

		st.push(i);
	}

	int result = 0;
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		if (correct[i])
		{
			result = max(result, ++cnt);
		}
		else
		{
			cnt = 0;
		}
	}

	cout << result << "\n";

	return 0;
}