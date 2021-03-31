#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int TEST_SET = 3;

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

	return false;
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

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 0;t < TEST_SET; t++)
	{
		int N;
		cin >> N;

		string sum = "0";

		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;

			// ���±����� �հ谡 ����
			if (sum[0] == '-')
			{
				// �Էµ� ������ ����
				if (s[0] == '-')
				{
					sum = add(sum.substr(1), s.substr(1));
					sum = "-" + sum;
				}
				// �Է��� ������ ���
				else
				{
					// �Էµ� ������ ���밪�� �� ���� ���
					if (isFormerBiggerThanLatter(sum.substr(1), s))
					{
						sum = subtract(sum.substr(1), s);
						sum = "-" + sum;
					}
					else
					{
						sum = subtract(s, sum.substr(1));
					}
				}
			}
			// ���±����� �հ谡 0 Ȥ�� ���
			else
			{
				// �Էµ� ������ ����
				if (s[0] == '-')
				{
					// �Էµ� ������ ���밪�� �� ���� ���
					if (isFormerBiggerThanLatter(sum, s.substr(1)))
					{
						sum = subtract(sum, s.substr(1));
					}
					else
					{
						// �Էµ� ������ ���밪�� �� Ŭ ���
						sum = subtract(s.substr(1), sum);
						sum = "-" + sum;
					}
				}
				// �Էµ� ������ ���
				else
				{
					sum = add(sum, s);
				}
			}
		}

		if (sum == "0" || sum == "-0")
		{
			cout << 0 << "\n";
		}
		else if (sum[0] == '-')
		{
			cout << "-\n";
		}
		else
		{
			cout << "+\n";
		}
	}

	return 0;
}