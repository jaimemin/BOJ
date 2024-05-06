#include <iostream>
#include <vector>
using namespace std;

int N, M, K; 

long long sum(vector<long long>& v, int idx)
{
	long long result = 0;

	while (idx)
	{
		result += v[idx];

		idx -= (idx & -idx);
	}

	return result;
}

void update(vector<long long>& v, int idx, long long diff)
{
	while (idx < v.size())
	{
		v[idx] += diff;

		idx += (idx & -idx);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;

	vector<long long> arr(N + 1);
	vector<long long> v(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];

		update(v, i, arr[i]);
	}

	M += K;

	while (M--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			long long diff = c - arr[b];
			arr[b] = c;

			update(v, b, diff);
		}
		else
		{
			cout << sum(v, c) - sum(v, b - 1) << "\n";
		}
	}

	return 0;
}