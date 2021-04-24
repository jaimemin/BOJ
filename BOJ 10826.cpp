#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 10000 + 1;

// �տ� ���ʿ��� 0�� ����
string getResultWithoutUnnecessaryZeros(string result)
{
	// ���ʷ� 0�� �ƴ� �ε����� ã�´�
	int firstNonZeroIdx = result.size();

	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] != '0')
		{
			firstNonZeroIdx = i;

			break;
		}
	}

	// ��� �ڸ��� 0�̶�� 0�� ��ȯ
	if (firstNonZeroIdx == result.size())
	{
		return "0";
	}

	// ���ʷ� 0�� �ƴ� �ڸ������� ���ڵ��� ��ȯ
	return result.substr(firstNonZeroIdx);
}

// bigInteger ���� �Լ�
string add(string s1, string s2)
{
	// ������ ��� ���̴� �ּ� s1�� s2 �� �� ū ������ ����
	string result(max(s1.size(), s2.size()), '0');

	bool carry = false;

	// �������� ���� ����
	for (int i = 0; i < result.size(); i++)
	{
		int temp = carry;
		carry = false;

		if (i < s1.size())
		{
			temp += s1[s1.size() - i - 1] - '0';
		}

		if (i < s2.size())
		{
			temp += s2[s2.size() - i - 1] - '0';
		}

		if (temp >= 10)
		{
			carry = true;

			temp -= 10;
		}

		result[result.size() - i - 1] = temp + '0';
	}

	// ���������� ĳ���� �ִٸ� �� �տ� 1 �߰�
	if (carry)
	{
		result.insert(result.begin(), '1');
	}

	return getResultWithoutUnnecessaryZeros(result);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	string fibonacci[MAX];
	fibonacci[0] = "0";
	fibonacci[1] = "1";

	for (int i = 2; i <= n; i++)
	{
		fibonacci[i] = add(fibonacci[i - 1], fibonacci[i - 2]);
	}

	cout << fibonacci[n] << "\n";

	return 0;
}
