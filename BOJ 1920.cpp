#include <iostream>
#include <set>
using namespace std;

set<long long> visited;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		visited.insert(num);
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;

		cout << (visited.find(num) != visited.end()) << "\n";
	}

	return 0;
}
