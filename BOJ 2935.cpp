#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

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

//bigInteger 곱셈 구현
string multiply(string s1, string s2)
{
	string result = "0";

	// 곱셈 과정을 그대로 구현
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

		// 곱셈 과정을 생각해보면 0을 뒤에 붙여주는 이유를 알 것입니다.
		line += string(i, '0');

		result = add(result, line);
	}

	return getResultWithoutUnnecessaryZeros(result);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string A, op, B;
	cin >> A >> op >> B;

	if (op == "+")
	{
		cout << add(A, B) << "\n";
	}
	else
	{
		cout << multiply(A, B) << "\n";
	}

	return 0;
}