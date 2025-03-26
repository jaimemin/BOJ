#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

const long long INF = 1e18;

vector<long long> computeCandidate(vector<long long>& prev, long long A, int tmax, int N)
{
    vector<long long> candidate(N + 1, INF);
    deque<int> dq;
    dq.push_back(0);

    for (int j = 1; j <= N; j++) 
    {
        while (!dq.empty() && dq.front() < j - tmax) 
        {
            dq.pop_front();
        }

        if (!dq.empty()) 
        {
            int idx = dq.front();

            candidate[j] = j * A + (prev[idx] - idx * A);
        }

        while (!dq.empty() && (prev[j] - j * A) <= (prev[dq.back()] - dq.back() * A)) 
        {
            dq.pop_back();
        }

        dq.push_back(j);
    }

    return candidate;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> menus(M);

    for (int i = 0; i < M; i++) 
    {
        long long price, quantity;
        cin >> price >> quantity;

        menus[i] = { price, quantity };
    }

    sort(menus.begin(), menus.end(), [](auto& a, auto& b) {
        return a.first < b.first;
    });

    vector<vector<long long>> dp(M + 1, vector<long long>(N + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i < M; i++) 
    {
        long long A = menus[i].first;
        long long quantity = menus[i].second;
        int tmax = min((long long)N, quantity);

        vector<vector<long long>> newDp = dp;

        for (int d = M - 1; d >= 0; d--) 
        {
            vector<long long>& prev = dp[d];
            vector<long long> candidate = computeCandidate(prev, A, tmax, N);

            for (int j = 1; j <= N; j++) 
            {
                if (candidate[j] < newDp[d + 1][j])
                {
                    newDp[d + 1][j] = candidate[j];
                }
            }
        }

        dp = move(newDp);
    }

    long long answer = INF;

    for (int d = 1; d <= M; d++) 
    {
        if (dp[d][N] < INF) 
        {
            long long candidate = d * dp[d][N];
            
            answer = min(answer, candidate);
        }
    }
    cout << answer << "\n";

    return 0;
}