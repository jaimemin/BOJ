#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
  dp[i][l]: "v[i]"를 '첫 원소'로 하는 길이 l짜리 수열을 만들었을 때,
            얻을 수 있는 합의 최댓값 (불가능하면 -∞로 표시)

  bestNext[i][l]: i에서 이어갈 수 있는 모든 j ∈ next(i)에 대해
                  dp[j][l]의 최댓값 (불가능하면 -∞)

  점화:
    dp[i][0] = 0
    dp[i][l] = max_{p=1..min(l,c[i])} [ p*v[i] + (bestNext[i][l-p] or 0) ]
      (단, l-p=0이면 뒤를 잇지 않는 경우이므로 p*v[i]가 그 자체로 가능)

  next(i): x[j] % x[i] == 0 && j>i
           (x는 오름차순 정렬로, x[i] ≤ x[j] 이때만 배수 관계 가능)
*/

const long long NEG_INF = LLONG_MIN; // 큰 음수로 불가능 상태 표시

const int MAX = 500 + 50;

long long dp[MAX][MAX];

long long bestNextArr[MAX][MAX]; // bestNextArr[i][l] = max_{ j ∈ next(i) } dp[j][l]

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<long long> x(M), c(M);

    for (int i = 0; i < M; i++)
    {
        cin >> x[i] >> c[i];
    }

    // (1) x_i 기준 오름차순 정렬
    vector<pair<long long, long long>> tmp(M);

    for (int i = 0; i < M; i++)
    {
        tmp[i] = { x[i], c[i] };
    }

    sort(tmp.begin(), tmp.end(), [](auto& a, auto& b) {
        return a.first < b.first;
    });

    for (int i = 0; i < M; i++)
    {
        x[i] = tmp[i].first;
        c[i] = tmp[i].second;

        if (c[i] > N)
        {
            c[i] = N; // N개 초과로 같은 정수 쓸 일은 없음
        }
    }

    // (2) next 리스트 구성
    //     next[i] = { j | x[j] % x[i] == 0 && j>i }
    vector<vector<int>> nxt(M);

    for (int i = 0; i < M; i++) 
    {
        for (int j = i + 1; j < M; j++) 
        {
            if (x[j] % x[i] == 0) 
            {
                nxt[i].push_back(j);
            }
        }
    }

    // (3) dp, bestNextArr 초기화
    for (int i = 0; i < M; i++)
    {
        for (int l = 0; l <= N; l++) 
        {
            dp[i][l] = NEG_INF;        // 초기엔 불가능으로 둠

            bestNextArr[i][l] = NEG_INF;
        }

        dp[i][0] = 0; // 길이 0이면 합 0
    }

    // **중요**: i를 큰 인덱스부터( M-1 ~ 0 ) 내려가며 dp 계산
    //           왜냐하면 dp[i][l]가 dp[j][..] (j>i)를 참고하기 때문
    for (int i = M - 1; i >= 0; i--)
    {
        // 먼저 bestNextArr[i][l] = max_{j in nxt[i]} dp[j][l] 갱신
        // i보다 큰 j들의 dp가 이미 계산되어 있으므로 여기서 바로 구할 수 있음
        for (int l = 0; l <= N; l++) 
        {
            long long bestVal = NEG_INF;

            for (int j : nxt[i]) 
            {
                bestVal = max(bestVal, dp[j][l]);
            }

            bestNextArr[i][l] = bestVal;
        }

        // 이제 dp[i][l] 계산
        for (int l = 1; l <= N; l++) 
        {
            // p = 1..min(l,c[i])만큼 v[i]를 연속 사용
            // 이후 나머지 l-p개는 next(i)에 속한 정수로 구성
            int limitP = min((long long)l, c[i]);
            long long bestVal = NEG_INF;

            for (int p = 1; p <= limitP; p++)
            {
                long long sumNow = p * x[i]; // v[i]를 p번 사용
                int rem = l - p;

                if (rem == 0)
                {
                    // 뒤를 추가로 잇지 않아도 l개 완성
                    bestVal = max(bestVal, sumNow);

                    continue;
                }

                // rem > 0 이면, bestNextArr[i][rem] 참고
                long long tail = bestNextArr[i][rem];

                if (tail != NEG_INF) 
                {
                    bestVal = max(bestVal, sumNow + tail);
                }
            }

            dp[i][l] = bestVal;
        }
    }

    // (4) 정답 구하기
    // 모든 i에 대해 dp[i][N]의 최댓값을 찾는다.
    long long answer = NEG_INF;

    for (int i = 0; i < M; i++)
    {
        answer = max(answer, dp[i][N]);
    }

    cout << (answer == NEG_INF ? -1 : answer) << "\n";

    return 0;
}