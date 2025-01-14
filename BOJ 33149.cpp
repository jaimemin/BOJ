#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e4 + 1e2;

// 충분히 큰 값(오버플로 방지용)
const long long INF = (long long)1e14;

int N, U;

int c[MAX];              // c[u] : 도시(u)의 전투력 (1-based)

vector<int> adj[MAX];    // 인접 리스트 (1-based)

// dp[u][s] = 서브트리(u)에서 "u가 포함된 국가(연결 컴포넌트)"의 전투력 합이 s일 때
//            이미 확정된(닫힌) 다른 국가들의 (U-w)^2 합의 최소값
long long dp[MAX][101];

// bestCost[u] = 서브트리(u)를 전부 분할 완료(닫음)했을 때의 최소값
long long bestCost[MAX];

// 트리 DP 함수
void dfs(int u, int parent)
{
    // 1) dp[u] 초기화: 모두 INF
    for (int s = 0; s <= U; s++) 
    {
        dp[u][s] = INF;
    }

    // 자기 자신만 포함하는 컴포넌트 => 전투력 c[u]
    dp[u][c[u]] = 0LL;

    // 2) 자식들 처리
    for (int v : adj[u]) 
    {
        if (v == parent)
        {
            continue;
        }

        // 자식 먼저 dfs
        dfs(v, u);

        // 이제 dp[v], bestCost[v]가 준비됨
        // => dp[u]와 dp[v]를 배낭(knapsack)처럼 merge
        static long long newDp[101];  // 임시 배열

        // 매번 newDp를 INF로 초기화
        for (int s = 0; s <= U; s++) 
        {
            newDp[s] = INF;
        }

        // 기존 dp[u][s1]를 가지고, 자식 v를 "닫거나(분할 완성)" / "연결" 하는 두 가지 경우
        for (int s1 = 0; s1 <= U; s1++)
        {
            long long costU = dp[u][s1];

            if (costU == INF)
            {
                continue; // 불가능 상태
            }

            // (a) v 서브트리를 "닫아버리기" -> bestCost[v] 추가
            {
                long long cand = costU + bestCost[v];

                // s1 변화 없음 (v를 연결 안 했으므로, u 컴포넌트 합은 그대로 s1)
                if (cand < newDp[s1]) 
                {
                    newDp[s1] = cand;
                }
            }

            // (b) v 서브트리를 "연결" -> dp[v][s2]와 합쳐서 s1 + s2 <= U
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

        // merge 결과를 dp[u]에 반영
        for (int s = 0; s <= U; s++) 
        {
            dp[u][s] = newDp[s];
        }
    }

    // 3) 서브트리 u를 "닫는다(분할 완료)" 했을 때 비용 = min_{s} [ dp[u][s] + (U-s)^2 ]
    long long bestVal = INF;

    for (int s = 0; s <= U; s++) 
    {
        if (dp[u][s] == INF)
        {
            continue;
        }

        // u 컴포넌트가 최종적으로 전투력합 s로 "닫힘"
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

    // DFS(1, -1)로 트리 DP 시작
    dfs(1, -1);

    // 전체 트리를 다 닫았을 때의 최소 비용은 bestCost[1]
    cout << bestCost[1] << "\n";

    return 0;
}
