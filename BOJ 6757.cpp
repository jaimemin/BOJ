#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isPalindrome(int X, int b)
{
	vector<int> v;

	while (X)
	{
		v.push_back(X%b);

		X /= b;
	}

	int vSize = v.size();

	for (int i = 0; i < vSize / 2; i++)
	{
		if (v[i] != v[vSize - (i + 1)])
		{
			return false;
		}
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int X;
	cin >> X;

	set<int> result;

	for (int b = 2; b * b < X; b++)
	{
		if (isPalindrome(X, b))
		{
			result.insert(b);
		}
	}

	for (int b = 1; b * b + b < X; b++)
	{
		if (X % b == 0)
		{
			result.insert(X / b - 1);
		}
	}

	for (int b : result)
	{
		cout << b << "\n";
	}

	return 0;
}