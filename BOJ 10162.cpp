#include <iostream>
using namespace std;

void printResult(int T)
{
	// 5분 (300초)
	int cnt = 0;

	while (T >= 300)
	{
		cnt++;

		T -= 300;
	}

	cout << cnt << " ";

	cnt = 0;

	// 1분 (60초)
	while (T >= 60)
	{
		cnt++;

		T -= 60;
	}

	cout << cnt << " ";

	cnt = 0;

	// 10초
	while (T)
	{
		cnt++;

		T -= 10;
	}

	cout << cnt << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	// 불가능한 경우 미리 예외처리
	if (T % 10)
	{
		cout << -1 << "\n";

		return 0;
	}

	printResult(T);

	return 0;
}