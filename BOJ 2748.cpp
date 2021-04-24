/*
F(0) = 0, F(1) = 1일 때 피보나치 수열은 F(n) = F(n - 1) + F(n - 2)이다(n >= 2)

이 때 행렬을 사용하면

┌F(n + 1) F(n)┐ = ┌1 1┐

└F(n) F(n - 1)┘   └1 0┘의 n 승

*/

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 2;
const int MOD = 1000000;

class Fibonacci
{
private:
	long long fibonacci[MAX][MAX];
public:
	Fibonacci()
	{
		memset(fibonacci, 0, sizeof(fibonacci));
	}

	Fibonacci &operator*(Fibonacci &f)
	{
		Fibonacci result;

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				result.fibonacci[i][j] = 0;
			}
		}

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				for (int k = 0; k < MAX; k++)
				{
					result.fibonacci[i][j] += (fibonacci[i][k] * f.fibonacci[k][j]) % MOD;
				}
			}
		}

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				fibonacci[i][j] = result.fibonacci[i][j];
			}
		}

		return *this;
	}

	long long *operator[] (int i)
	{
		return fibonacci[i];
	}

	long long answer(void)
	{
		return fibonacci[0][1];
	}
};

Fibonacci formula, base;

void initialize(void)
{
	formula[0][0] = formula[0][1] = formula[1][0] = 1;
	formula[1][1] = 0;

	base[0][0] = base[1][1] = 1;
	base[0][1] = base[1][0] = 0;
}

Fibonacci pow(Fibonacci &f, long long n)
{
	if (n == 0)
	{
		return base;
	}

	if (n == 1)
	{
		return formula;
	}

	if (n % 2)
	{
		return pow(f, n - 1) * f;
	}

	Fibonacci half = pow(f, n / 2);

	return half * half;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long N;
	cin >> N;

	initialize();

	Fibonacci result = pow(formula, N);

	cout << result.answer() % MOD << "\n";

	return 0;
}
