#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double h, w;
	cin >> h >> w;

	if (w > h)
	{
		swap(w, h);
	}

	// ���̰� ������ 3�� �̻� Ŭ ���
	if (h >= 3 * w)
	{
		printf("%.4lf\n", w);
	}
	else if (10 * h >= 15 * w)
	{
		// ���̰� ������ 1.5�� ũ�� 3�� �̸��� ��
		printf("%.4lf\n", h / 3);
	}
	else
	{
		// ���̰� ���� 1.5�� �̸��� ��
		printf("%.4lf\n", w / 2);
	}

	return 0;
}