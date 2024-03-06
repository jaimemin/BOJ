#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;

	vector<int> temperatures;

	for (int i = 0; i < N; i++)
	{
		int temperature;
		cin >> temperature;

		temperatures.push_back(temperature);
	}

	int answer = 0;
	int sum = 0;

	for (int i = 0; i < K; i++)
	{
		sum += temperatures[i];
	}

	answer = sum;
	int idx = 0, idx2 = K;

	while (idx2 < N)
	{
		sum += (temperatures[idx2++] - temperatures[idx++]);

		answer = max(answer, sum);
	}

	cout << answer << "\n";

	return 0;
}