#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int TEST_SET = 3;

// 앞에 불필요한 0을 제거
string getResultWithoutUnnecessaryZeros(string result)
{
	// 최초로 0이 아닌 인덱스를 찾는다
	int firstNonZeroIdx = result.size();

	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] != '0')
		{
			firstNonZeroIdx = i;

			break;
		}
	}

	// 모든 자리가 0이라면 0을 반환
	if (firstNonZeroIdx == result.size())
	{
		return "0";
	}

	// 최초로 0이 아닌 자리부터의 숫자들을 반환
	return result.substr(firstNonZeroIdx);
}

// bigInteger 덧셈 함수
string add(string s1, string s2)
{
	// 덧셈의 결과 길이는 최소 s1과 s2 중 더 큰 숫자의 길이
	string result(max(s1.size(), s2.size()), '0');

	bool carry = false;

	// 끝에부터 더해 나감
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

	// 마지막에도 캐리가 있다면 맨 앞에 1 추가
	if (carry)
	{
		result.insert(result.begin(), '1');
	}

	return getResultWithoutUnnecessaryZeros(result);
}

// s1이 s2보다 큰 지 여부를 판별하는 함수
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

// bigInteger 뺄셈 함수 (부호는 판별 X)
string subtract(string s1, string s2)
{
	// 절댓값 기준 s1과 s2 중 더 큰 수로부터 더 작은 수를 빼는 함수이므로
	if (isFormerBiggerThanLatter(s1, s2) == false)
	{
		swap(s1, s2);
	}

	// s1과 s2를 거꾸로 뒤집는다
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	// 더 큰 수로부터 더 작은 수를 빼므로 add 함수와 달리 result를 s1으로 초기화
	string result = s1;

	int carry = 0;

	for (int i = 0; i < result.size(); i++)
	{
		int tempCarry = carry;
		carry = 0;

		// carry가 존재한다면 s1[i]로부터 1 뺌
		int temp = (s1[i] - '0') - tempCarry;

		// 음수가 된다면 carry가 존재한다고 표시 후 10을 더해줌
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

	// carry가 있다면 마지막 자리 숫자 1 빼줌
	if (carry)
	{
		int lastDigit = result[result.size() - 1];
		lastDigit--;

		result[result.size() - 1] = lastDigit + '0';
	}

	// 다시 뒤집어준 뒤
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

			// 여태까지의 합계가 음수
			if (sum[0] == '-')
			{
				// 입력된 정수가 음수
				if (s[0] == '-')
				{
					sum = add(sum.substr(1), s.substr(1));
					sum = "-" + sum;
				}
				// 입려된 정수가 양수
				else
				{
					// 입력된 정수의 절대값이 더 작을 경우
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
			// 여태까지의 합계가 0 혹은 양수
			else
			{
				// 입력된 정수가 음수
				if (s[0] == '-')
				{
					// 입력된 정수의 절대값이 더 작을 경우
					if (isFormerBiggerThanLatter(sum, s.substr(1)))
					{
						sum = subtract(sum, s.substr(1));
					}
					else
					{
						// 입력된 정수의 절대값이 더 클 경우
						sum = subtract(s.substr(1), sum);
						sum = "-" + sum;
					}
				}
				// 입력된 정수가 양수
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