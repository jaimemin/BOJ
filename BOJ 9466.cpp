#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1e5 + 100;

int T, N;
int students[MAX];
int result;
vector<int> traces;
bool completed[MAX];
bool visited[MAX];

void init(void)
{
	memset(students, 0, sizeof(students));
	memset(completed, false, sizeof(completed));
	memset(visited, false, sizeof(visited));
}

void DFS(int student)
{
	visited[student] = true;

	int next = students[student];

	if (visited[next] == false)
	{
		DFS(next);
	}
	else if (completed[next] == false)
	{
		for (int node = next; node != student; node = students[node])
		{
			result--;
		}

		result--;
	}

	completed[student] = true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		init();

		cin >> N;

		result = N;

		for (int n = 1; n <= N; n++)
		{
			cin >> students[n];
		}

		for (int n = 1; n <= N; n++)
		{
			if (visited[n])
			{
				continue;
			}

			DFS(n);
		}

		cout << result << "\n";
	}

	return 0;
}