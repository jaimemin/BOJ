#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int result = 0;

	while (N--)
	{
		stack<char> st;
		string s;
		cin >> s;

		for (char c : s)
		{
			st.push(c);
			
			while (st.size() >= 2)
			{
				char top = st.top();
				st.pop();

				if (top == st.top())
				{
					st.pop();
				}
				else
				{
					st.push(top);

					break;
				}
			}
		}

		result += st.empty();
	}

	cout << result << "\n";

	return 0;
}