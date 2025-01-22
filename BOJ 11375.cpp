#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1001;

vector<int> work[MAX]; // ������ �� �� �ִ� �� ���

int assigned[MAX];     // �� �Ͽ� �Ҵ�� ����

bool visited[MAX];     // �湮 ����

// DFS�� �̿��� �̺� ��Ī
bool dfs(int employee)
{
    for (int task : work[employee])
    {
        if (visited[task])
        {
            continue;
        }

        visited[task] = true;

        // ���� ����ְų�, �̹� �Ҵ�� ������ �ٸ� ���� �õ��� �� �� ������ ��Ī
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