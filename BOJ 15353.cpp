#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string A, B;
	cin >> A >> B;

	string result = "";

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int carry = 0;

	for (int i = 0; i < min(A.length(), B.length()); i++)
	{
		int sum = (A[i] - '0') + (B[i] - '0') + carry;
		carry = 0;

		if (sum >= 10)
		{
			sum -= 10;
			carry = 1;
		}

		result += to_string(sum);
	}

	for (int i = min(A.length(), B.length()); i < A.length(); i++)
	{
		int sum = (A[i] - '0') + carry;
		carry = 0;

		if (sum >= 10)
		{
			sum -= 10;
			carry = 1;
		}

		result += to_string(sum);
	}

	for (int i = min(A.length(), B.length()); i < B.length(); i++)
	{
		int sum = (B[i] - '0') + carry;
		carry = 0;

		if (sum >= 10)
		{
			sum -= 10;
			carry = 1;
		}

		result += to_string(sum);
	}

	if (carry)
	{
		result += "1";
	}

	reverse(result.begin(), result.end());

	cout << result << "\n";

	return 0;
}