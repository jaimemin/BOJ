#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

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

	return result;
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

	return true;
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
		// 둘 다 양수
		cout << add(A, B) << "\n";
	}
	else if (APositive == false && BPositive == false)
	{
		// 둘 다 음수
		cout << "-" << add(A.substr(1), B.substr(1)) << "\n";
	} 
	else if (APositive && BPositive == false)
	{
		// A 양수, B 음수
		string tempResult = subtract(A, B.substr(1));

		// 절댓값 기준 A가 B보다 크거나 연산결과가 0이라면 결과는 양수
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
		// A 음수, B 양수
		string tempResult = subtract(A.substr(1), B);

		// 절댓값 기준 A가 B보다 크거나 연산결과가 0이 아니라면 결과는 음수
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