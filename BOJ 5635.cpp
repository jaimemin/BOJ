#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef struct
{
	int y;
	int m;
	int d;
} BirthDate;

bool operator<(const BirthDate& a, const BirthDate& b)
{
	if (a.y < b.y)
	{
		return true;
	}

	if (a.y == b.y)
	{
		if (a.m < b.m)
		{
			return true;
		}

		if (a.m == b.m)
		{
			return a.d < b.d;
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vector<BirthDate> v;
	map<BirthDate, string> birthDate2name;

	while (n--)
	{
		string s;
		int d, m, y;
		cin >> s >> d >> m >> y;

		v.push_back({ y, m, d });
		birthDate2name[{ y, m, d }] = s;
	}

	sort(v.begin(), v.end());

	cout << birthDate2name[v.back()] << "\n" << birthDate2name[v[0]] << "\n";

	return 0;
}