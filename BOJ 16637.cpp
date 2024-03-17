#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

int N;

long long result = LLONG_MIN;

string s;

long long getResult(string temp)
{
	vector<string> formula;
	stack<char> st;
	bool insideParenthesis = false;

	for (char c : temp)
	{
		vector<char> v;

		if (c == ')')
		{
			while (st.top() != '(')
			{
				v.push_back(st.top());
				st.pop();
			}

			st.pop();

			switch (v[1])
			{
			case '+':
				formula.push_back(to_string((v[0] - '0') + (v[2] - '0')));

				break;
			case '-':
				formula.push_back(to_string((v[2] - '0') - (v[0] - '0')));

				break;
			case '*':
				formula.push_back(to_string((v[0] - '0') * (v[2] - '0')));

				break;
			}

			insideParenthesis = false;
			continue;
		}

		if (c == '(')
		{
			insideParenthesis = true;
		}

		if (insideParenthesis)
		{
			st.push(c);
		}
		else
		{
			string str(1, c);
			formula.push_back(str);
		}
	}

	long long sum = stoll(formula[0]);

	for (int i = 0; i < formula.size() - 2; i += 2)
	{
		if (formula[i + 1] == "+")
		{
			sum += stoll(formula[i + 2]);
		}
		else if (formula[i + 1] == "-")
		{
			sum -= stoll(formula[i + 2]);
		}
		else
		{
			sum *= stoll(formula[i + 2]);
		}
	}

	return sum;
}

void func(int idx, string temp)
{
	if (idx == s.length())
	{
		result = max(result, getResult(temp));

		return;
	}

	if (s[idx] >= '0' && s[idx] <= '9')
	{
		func(idx + 1, temp + s[idx]);
	}
	else
	{
		func(idx + 1, temp + s[idx]);

		if (idx + 3 < s.length())
		{
			func(idx + 4, temp + s[idx] + '(' + s.substr(idx + 1, 3) + ")");
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> s;

	if (N == 1)
	{
		cout << s[0] - '0' << "\n";

		return 0;
	}

	string temp = "";
	func(0, temp);

	cout << result << "\n";

	return 0;
}