#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, I;
	cin >> A >> I;

	// �ø��̹Ƿ� ����� (I - 1)�� �Ǵ� ��ε� �������� 1 �����ָ� ��
	int result = A * (I - 1) + 1;

	cout << result << "\n";

	return 0;
}