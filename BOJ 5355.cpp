#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t <= T; t++)
	{
		string s;
		getline(cin, s);

		stringstream stream;
		stream.str(s);

		string input;
		vector<string> v;

		while (stream >> input)
		{
			v.push_back(input);
		}

		if (v.empty())
		{
			continue;
		}

		double num = stod(v[0]);

		for (int i = 1; i < v.size(); i++)
		{
			if (v[i] == "@")
			{
				num *= 3;
			}
			else if (v[i] == "%")
			{
				num += 5;
			}
			else
			{
				num -= 7;
			}
		}

		printf("%.2lf\n", num);
	}

	return 0;
}