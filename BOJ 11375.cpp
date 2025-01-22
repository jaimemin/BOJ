#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1001;

vector<int> work[MAX]; // 직원별 할 수 있는 일 목록

int assigned[MAX];     // 각 일에 할당된 직원

bool visited[MAX];     // 방문 여부

// DFS를 이용한 이분 매칭
bool dfs(int employee)
{
    for (int task : work[employee])
    {
        if (visited[task])
        {
            continue;
        }

        visited[task] = true;

        // 일이 비어있거나, 이미 할당된 직원이 다른 일을 맡도록 할 수 있으면 매칭
        if (assigned[task] == -1 || dfs(assigned[task]))
        {
            assigned[task] = employee;

            return true;
        }
    }

    return false;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) 
    {
        int cnt;
        cin >> cnt;

        while (cnt--) 
        {
            int task;
            cin >> task;

            work[i].push_back(task);
        }
    }

    memset(assigned, -1, sizeof(assigned));

    int maxMatch = 0;

    for (int i = 1; i <= N; i++)
    {
        memset(visited, false, sizeof(visited));

        if (dfs(i))
        {
            maxMatch++;
        }
    }

    cout << maxMatch << "\n";

    return 0;
}