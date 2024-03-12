#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string deleteMeaninglessZeros(string temp)
{
	int idx = -1;

	for (int i = 0; i < temp.length(); i++)
	{
		if (temp[i] != '0')
		{
			idx = i;

			break;
		}
	}

	return idx == -1 ? "0" : temp.substr(idx);
}

bool cmp(string& a, string& b)
{
	if (a.length() < b.length())
	{
		return true;
	}

	if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); i++) 
		{
			if (a[i] < b[i])
			{
				return true;
			}

			if (a[i] > b[i])
			{
				return false;
			}
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	vector<string> v;

	while (N--)
	{
		string s;
		cin >> s;

		string temp;

		for (char c : s)
		{
			if (c >= '0' && c <= '9')
			{
				temp += c;
			}
			else
			{
				if (temp != "")
				{
					v.push_back(deleteMeaninglessZeros(temp));
				}

				temp = "";
			}
		}

		if (temp != "")
		{
			v.push_back(deleteMeaninglessZeros(temp));
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (string s : v)
	{
		cout << s << "\n";
	}

	return 0;
}