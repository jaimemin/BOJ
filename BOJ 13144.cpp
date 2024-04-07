#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e5 + 1;

long long visited[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	long long left = 0, right = 0;
	long long result = 0;

	while (right < N)
	{
		if (!visited[v[right]])
		{
			visited[v[right++]]++;
		}
		else
		{
			result += (right - left);
			visited[v[left++]]--;
		}
	}

	result += (right - left) * (right - left + 1) / 2;

	cout << result << "\n";

	return 0;
}