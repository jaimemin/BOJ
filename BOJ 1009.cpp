#include <iostream>
using namespace std;

const int MAX = 10;

int getCycleCnt(int a)
{
	bool visited[MAX] = { false, };

	int cnt = 1;
	visited[a % MAX] = true;
	int copyA = a;

	while (true)
	{
		a *= copyA;
		a %= MAX;

		if (visited[a])
		{
			break;
		}

		cnt++;
	}

	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int a, b;
		cin >> a >> b;

		int copyA = a;
		int cycleCnt = getCycleCnt(a);
		int powCnt = (b % cycleCnt) == 0 ? cycleCnt : (b % cycleCnt);

		for (int i = 1; i < powCnt; i++)
		{
			a *= copyA;
			a %= MAX;
		}

		a %= MAX;

		cout << (a == 0 ? 10 : a) << "\n";
	}

	return 0;
}