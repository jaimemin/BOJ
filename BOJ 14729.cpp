#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	priority_queue<double, vector<double>, greater<double>> pq;

	for (int i = 0; i < N; i++)
	{
		double score;
		cin >> score;

		pq.push(score);
	}

	for (int i = 0; i < 7; i++)
	{
		printf("%.3lf\n", pq.top());

		pq.pop();
	}

	return 0;
}