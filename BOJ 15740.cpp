#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

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

	return result;
}

// s1�� s2���� ū �� ���θ� �Ǻ��ϴ� �Լ�
bool isFormerBiggerThanLatter(string s1, string s2)
{
	if (s1.size() != s2.size())
	{
		return s1.size() > s2.size();
	}

	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == s2[i])
		{
			continue;
		}

		return s1[i] > s2[i];
	}

	return true;
}

// bigInteger ���� �Լ� (��ȣ�� �Ǻ� X)
string subtract(string s1, string s2)
{
	// ���� ���� s1�� s2 �� �� ū ���κ��� �� ���� ���� ���� �Լ��̹Ƿ�
	if (isFormerBiggerThanLatter(s1, s2) == false)
	{
		swap(s1, s2);
	}

	// s1�� s2�� �Ųٷ� �����´�
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	// �� ū ���κ��� �� ���� ���� ���Ƿ� add �Լ��� �޸� result�� s1���� �ʱ�ȭ
	string result = s1;
	
	int carry = 0;

	for (int i = 0; i < result.size(); i++)
	{
		int tempCarry = carry;
		carry = 0;

		// carry�� �����Ѵٸ� s1[i]�κ��� 1 ��
		int temp = (s1[i] - '0') - tempCarry;

		// ������ �ȴٸ� carry�� �����Ѵٰ� ǥ�� �� 10�� ������
		if (temp < 0)
		{
			carry = 1;
			temp += 10;
		}
		
		if (i < s2.size())
		{
			temp -= (s2[i] - '0');

			if (temp < 0)
			{
				carry = 1;
				temp += 10;
			}
		}

		result[i] = temp + '0';
	}

	// carry�� �ִٸ� ������ �ڸ� ���� 1 ����
	if (carry)
	{
		int lastDigit = result[result.size() - 1];
		lastDigit--;

		result[result.size() - 1] = lastDigit + '0';
	}

	// �ٽ� �������� ��
	reverse(result.begin(), result.end());

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

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string A, B;
	cin >> A >> B;

	int APositive = A[0] != '-';
	int BPositive = B[0] != '-';

	if (APositive && BPositive)
	{
		// �� �� ���
		cout << add(A, B) << "\n";
	}
	else if (APositive == false && BPositive == false)
	{
		// �� �� ����
		cout << "-" << add(A.substr(1), B.substr(1)) << "\n";
	} 
	else if (APositive && BPositive == false)
	{
		// A ���, B ����
		string tempResult = subtract(A, B.substr(1));

		// ���� ���� A�� B���� ũ�ų� �������� 0�̶�� ����� ���
		if (isFormerBiggerThanLatter(A, B.substr(1)) || tempResult == "0")
		{
			cout << tempResult << "\n";
		}
		else
		{
			cout << "-" << tempResult << "\n";
		}
	}
	else if (APositive == false && BPositive)
	{ 
		// A ����, B ���
		string tempResult = subtract(A.substr(1), B);

		// ���� ���� A�� B���� ũ�ų� �������� 0�� �ƴ϶�� ����� ����
		if (isFormerBiggerThanLatter(A.substr(1), B) && tempResult != "0")
		{
			cout << "-" << tempResult << "\n";
		}
		else
		{
			cout << tempResult << "\n";
		}
	}
	
	return 0;
}