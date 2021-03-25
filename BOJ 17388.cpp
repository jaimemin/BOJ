#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int HUNDRED = 100;
const int MAX = 3;

typedef struct
{
	int score;
	string name;
}University;

bool cmp(University a, University b)
{
	return a.score < b.score;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int S, K, H;
	cin >> S >> K >> H;

	if (S + K + H >= HUNDRED)
	{
		cout << "OK\n";

		return 0;
	}

	University universities[MAX] = { { S, "Soongsil" },{ K, "Korea" },{ H, "Hanyang" } };
	sort(universities, universities + MAX, cmp);

	cout << universities[0].name << "\n";

	return 0;
}