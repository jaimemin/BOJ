#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--)
	{
		string op;
		cin >> op;

		int N;
		cin >> N;

		string s;
		cin >> s;

		deque<int> dq;
		string temp = "";

		for (char c : s)
		{
			if (c == '[' || c == ']')
			{
				if (temp != "")
				{
					dq.push_back(stoi(temp));
				}

				continue;
			}

			if (c == ',')
			{
				dq.push_back(stoi(temp));
				temp = "";

				continue;
			}

			temp += c;
		}

		bool reversed = false;
		bool flag = true;

		for (char c : op)
		{
			if (c == 'R')
			{
				reversed = !reversed;

				continue;
			}

			if (dq.empty())
			{
				flag = false;

				break;
			}

			reversed ? dq.pop_back() : dq.pop_front();
		}

		if (!flag)
		{
			cout << "error\n";

			continue;
		}

		cout << "[";

		if (reversed)
		{
			for (int i = dq.size() - 1; i >= 0; i--)
			{
				cout << dq[i];

				if (i != 0)
				{
					cout << ",";
				}
			}
		}
		else
		{
			for (int i = 0; i < dq.size(); i++)
			{
				cout << dq[i];

				if (i != dq.size() - 1)
				{
					cout << ",";
				}
			}
		}

		cout << "]\n";
	}

	return 0;
}