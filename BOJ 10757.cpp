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

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string A, B;
	cin >> A >> B;

	cout << add(A, B) << "\n";

	return 0;
}