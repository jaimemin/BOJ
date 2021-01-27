#include <iostream>
#include <algorithm>
#include <cstring> //memset
using namespace std;

const int MAX = 300 + 1;
const int INF = 987654321;

int N, M, K;
int dist[MAX][MAX];
int cache[MAX][MAX]; //해당 도시, 몇번 방문?

int maxTaste(int idx, int visit)
{
	//기저 사례
	if (visit == M && idx != N)
	{
		return -INF;
	}

	//조건 성립
	if (idx == N)
	{
		return 0;
	}

	int &result = cache[idx][visit];

	if (result != -1)
	{
		return result;
	}

	result = -INF;

	//갈 수 있는 곳이면
	for (int to = idx + 1; to <= N; to++)
	{
		if (dist[idx][to])
		{
			result = max(result, dist[idx][to] + maxTaste(to, visit + 1));
		}
	}

	return result;
}

int main(void)
{
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		int city1, city2, taste;
		cin >> city1 >> city2 >> taste;

		//city1 -> city2 제일 맛있는 기내식을 채택
		dist[city1][city2] = max(dist[city1][city2], taste);
	}

	memset(cache, -1, sizeof(cache));

	cout << maxTaste(1, 1) << endl;

	return 0;
}