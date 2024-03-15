#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool balanced(string s)
{
	stack<char> st;

	for (char c : s)
	{
		if (!(c == '(' || c == ')' || c == '[' || c == ']'))
		{
			continue;
		}

		if (c == '(' || c == '[')
		{
			st.push(c);

			continue;
		}

		if (st.empty())
		{
			return false;
		}

		if (c == ')' && st.top() != '(')
		{
			return false;
		}

		if (c == ']' && st.top() != '[')
		{
			return false;
		}

		st.pop();
	}

	return st.empty();
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (true)
	{
		string s;
		getline(cin, s);

		if (s == ".")
		{
			break;
		}

		if (balanced(s))
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}

	return 0;
}