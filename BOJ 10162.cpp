#include <iostream>
using namespace std;

void printResult(int T)
{
	// 5�� (300��)
	int cnt = 0;

	while (T >= 300)
	{
		cnt++;

		T -= 300;
	}

	cout << cnt << " ";

	cnt = 0;

	// 1�� (60��)
	while (T >= 60)
	{
		cnt++;

		T -= 60;
	}

	cout << cnt << " ";

	cnt = 0;

	// 10��
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

	// �Ұ����� ��� �̸� ����ó��
	if (T % 10)
	{
		cout << -1 << "\n";

		return 0;
	}

	printResult(T);

	return 0;
}