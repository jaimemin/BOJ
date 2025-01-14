#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e4 + 1e2;

// ����� ū ��(�����÷� ������)
const long long INF = (long long)1e14;

int N, U;

int c[MAX];              // c[u] : ����(u)�� ������ (1-based)

vector<int> adj[MAX];    // ���� ����Ʈ (1-based)

// dp[u][s] = ����Ʈ��(u)���� "u�� ���Ե� ����(���� ������Ʈ)"�� ������ ���� s�� ��
//            �̹� Ȯ����(����) �ٸ� �������� (U-w)^2 ���� �ּҰ�
long long dp[MAX][101];

// bestCost[u] = ����Ʈ��(u)�� ���� ���� �Ϸ�(����)���� ���� �ּҰ�
long long bestCost[MAX];

// Ʈ�� DP �Լ�
void dfs(int u, int parent)
{
    // 1) dp[u] �ʱ�ȭ: ��� INF
    for (int s = 0; s <= U; s++) 
    {
        dp[u][s] = INF;
    }

    // �ڱ� �ڽŸ� �����ϴ� ������Ʈ => ������ c[u]
    dp[u][c[u]] = 0LL;

    // 2) �ڽĵ� ó��
    for (int v : adj[u]) 
    {
        if (v == parent)
        {
            continue;
        }

        // �ڽ� ���� dfs
        dfs(v, u);

        // ���� dp[v], bestCost[v]�� �غ��
        // => dp[u]�� dp[v]�� �賶(knapsack)ó�� merge
        static long long newDp[101];  // �ӽ� �迭

        // �Ź� newDp�� INF�� �ʱ�ȭ
        for (int s = 0; s <= U; s++) 
        {
            newDp[s] = INF;
        }

        // ���� dp[u][s1]�� ������, �ڽ� v�� "�ݰų�(���� �ϼ�)" / "����" �ϴ� �� ���� ���
        for (int s1 = 0; s1 <= U; s1++)
        {
            long long costU = dp[u][s1];

            if (costU == INF)
            {
                continue; // �Ұ��� ����
            }

            // (a) v ����Ʈ���� "�ݾƹ�����" -> bestCost[v] �߰�
            {
                long long cand = costU + bestCost[v];

                // s1 ��ȭ ���� (v�� ���� �� �����Ƿ�, u ������Ʈ ���� �״�� s1)
                if (cand < newDp[s1]) 
                {
                    newDp[s1] = cand;
                }
            }

            // (b) v ����Ʈ���� "����" -> dp[v][s2]�� ���ļ� s1 + s2 <= U
            for (int s2 = 0; s2 <= U; s2++)
            {
                long long costV = dp[v][s2];

                if (costV == INF)
                {
                    continue;
                }

                if (s1 + s2 <= U) 
                {
                    long long cand = costU + costV;
                    long long& ref = newDp[s1 + s2];

                    if (cand < ref)
                    {
                        ref = cand;
                    }
                }
            }
        }

        // merge ����� dp[u]�� �ݿ�
        for (int s = 0; s <= U; s++) 
        {
            dp[u][s] = newDp[s];
        }
    }

    // 3) ����Ʈ�� u�� "�ݴ´�(���� �Ϸ�)" ���� �� ��� = min_{s} [ dp[u][s] + (U-s)^2 ]
    long long bestVal = INF;

    for (int s = 0; s <= U; s++) 
    {
        if (dp[u][s] == INF)
        {
            continue;
        }

        // u ������Ʈ�� ���������� �������� s�� "����"
        long long cost = dp[u][s] + (long long)(U - s) * (U - s);

        if (cost < bestVal)
        {
            bestVal = cost;
        }
    }

    bestCost[u] = bestVal;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < N - 1; i++) 
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin >> U;

    // DFS(1, -1)�� Ʈ�� DP ����
    dfs(1, -1);

    // ��ü Ʈ���� �� �ݾ��� ���� �ּ� ����� bestCost[1]
    cout << bestCost[1] << "\n";

    return 0;
}
