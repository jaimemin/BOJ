#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--)
	{
		int N, M;
		cin >> N >> M;

		vector<int> A(N), B(M);

		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
		}

		for (int i = 0; i < M; i++)
		{
			cin >> B[i];
		}

		sort(B.begin(), B.end());

		int result = 0;

		for (int i = 0; i < N; i++)
		{
			auto it = lower_bound(B.begin(), B.end(), A[i]) - B.begin();

			result += it;
		}

		cout << result << "\n";
	}

	return 0;
}