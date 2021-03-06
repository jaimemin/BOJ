#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

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

	return getResultWithoutUnnecessaryZeros(result);
}

//bigInteger ���� ����
string multiply(string s1, string s2)
{
	string result = "0";

	// ���� ������ �״�� ����
	for (int i = 0; i < s2.size(); i++)
	{
		string line(s1);
		int carry = 0;

		for (int j = s1.size() - 1; j >= 0; j--)
		{
			int temp = carry;
			carry = 0;

			temp += (s1[j] - '0') * (s2[s2.size() - (i + 1)] - '0');

			if (temp >= 10)
			{
				carry = temp / 10;
				temp %= 10;
			}

			line[j] = temp + '0';
		}

		if (carry > 0)
		{
			line.insert(line.begin(), carry + '0');
		}

		// ���� ������ �����غ��� 0�� �ڿ� �ٿ��ִ� ������ �� ���Դϴ�.
		line += string(i, '0');

		result = add(result, line);
	}

	return getResultWithoutUnnecessaryZeros(result);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string A, B;
	cin >> A >> B;

	string addResult = add(A, B);
	string subtractResult = subtract(A, B);

	if (isFormerBiggerThanLatter(A, B) == false)
	{
		subtractResult = "-" + subtractResult;
	}

	string multiplyResult = "";

	if (subtractResult[0] == '-')
	{
		multiplyResult = multiply(addResult, subtractResult.substr(1));
		multiplyResult = '-' + multiplyResult;
	}
	else
	{
		multiplyResult = multiply(addResult, subtractResult);
	}

	cout << multiplyResult << "\n";

	return 0;
}