#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<long long> seq(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> seq[i];
    }

    vector<vector<int>> diffList(N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            diffList[i].push_back(int(seq[i] - seq[j]));
        }

        sort(diffList[i].begin(), diffList[i].end());
    }

    vector<vector<int>> cntList(N), lenList(N);

    for (int i = 0; i < N; i++) 
    {
        int sz = diffList[i].size();

        cntList[i].assign(sz, 0);
        lenList[i].assign(sz, 0);
    }

    long long answer = 0;

    for (int i = 0; i < N; i++)
    {
        auto& curDiff = diffList[i];
        auto& curCnt = cntList[i];
        auto& curLen = lenList[i];

        for (int j = i + 1; j < N; j++) 
        {
            int delta = int(seq[j] - seq[i]);
            int aggCnt = 0, aggLen = 0;

            for (int k = -1; k <= 1; k++)
            {
                int target = delta + k;
                auto it = lower_bound(curDiff.begin(), curDiff.end(), target);

                if (it != curDiff.end() && *it == target)
                {
                    int idx = int(it - curDiff.begin());

                    aggCnt = (aggCnt + curCnt[idx]) % MOD;
                    aggLen = (aggLen + curLen[idx]) % MOD;
                }
            }

            int newCnt = aggCnt + 1;

            if (newCnt >= MOD)
            {
                newCnt -= MOD;
            }

            int newLen = (aggLen + aggCnt) % MOD;
            newLen = (newLen + 2) % MOD;

            int addValue = (aggLen + aggCnt) % MOD;
            answer = (answer + addValue) % MOD;

            auto& nextDiff = diffList[j];
            auto& nextCnt = cntList[j];
            auto& nextLen = lenList[j];
            int idx2 = int(lower_bound(nextDiff.begin(), nextDiff.end(), delta) - nextDiff.begin());

            nextCnt[idx2] = (nextCnt[idx2] + newCnt) % MOD;
            nextLen[idx2] = (nextLen[idx2] + newLen) % MOD;
        }
    }

    cout << answer << "\n";

    return 0;
}