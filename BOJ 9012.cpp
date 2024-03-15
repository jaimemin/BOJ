#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	while (N--)
	{
		string s;
		cin >> s;

		stack<char> st;
		bool flag = true;

		for (char c : s)
		{
			if (c == '(')
			{
				st.push(c);

				continue;
			}

			if (st.empty() || st.top() != '(')
			{
				flag = false;

				break;
			}

			st.pop();
		}

		if (!flag)
		{
			cout << "NO\n";
		}
		else
		{
			if (st.empty())
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}

	return 0;
}