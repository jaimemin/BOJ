#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
  dp[i][l]: "v[i]"�� 'ù ����'�� �ϴ� ���� l¥�� ������ ������� ��,
            ���� �� �ִ� ���� �ִ� (�Ұ����ϸ� -�ķ� ǥ��)

  bestNext[i][l]: i���� �̾ �� �ִ� ��� j �� next(i)�� ����
                  dp[j][l]�� �ִ� (�Ұ����ϸ� -��)

  ��ȭ:
    dp[i][0] = 0
    dp[i][l] = max_{p=1..min(l,c[i])} [ p*v[i] + (bestNext[i][l-p] or 0) ]
      (��, l-p=0�̸� �ڸ� ���� �ʴ� ����̹Ƿ� p*v[i]�� �� ��ü�� ����)

  next(i): x[j] % x[i] == 0 && j>i
           (x�� �������� ���ķ�, x[i] �� x[j] �̶��� ��� ���� ����)
*/

const long long NEG_INF = LLONG_MIN; // ū ������ �Ұ��� ���� ǥ��

const int MAX = 500 + 50;

long long dp[MAX][MAX];

long long bestNextArr[MAX][MAX]; // bestNextArr[i][l] = max_{ j �� next(i) } dp[j][l]

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

    // (1) x_i ���� �������� ����
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
            c[i] = N; // N�� �ʰ��� ���� ���� �� ���� ����
        }
    }

    // (2) next ����Ʈ ����
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

    // (3) dp, bestNextArr �ʱ�ȭ
    for (int i = 0; i < M; i++)
    {
        for (int l = 0; l <= N; l++) 
        {
            dp[i][l] = NEG_INF;        // �ʱ⿣ �Ұ������� ��

            bestNextArr[i][l] = NEG_INF;
        }

        dp[i][0] = 0; // ���� 0�̸� �� 0
    }

    // **�߿�**: i�� ū �ε�������( M-1 ~ 0 ) �������� dp ���
    //           �ֳ��ϸ� dp[i][l]�� dp[j][..] (j>i)�� �����ϱ� ����
    for (int i = M - 1; i >= 0; i--)
    {
        // ���� bestNextArr[i][l] = max_{j in nxt[i]} dp[j][l] ����
        // i���� ū j���� dp�� �̹� ���Ǿ� �����Ƿ� ���⼭ �ٷ� ���� �� ����
        for (int l = 0; l <= N; l++) 
        {
            long long bestVal = NEG_INF;

            for (int j : nxt[i]) 
            {
                bestVal = max(bestVal, dp[j][l]);
            }

            bestNextArr[i][l] = bestVal;
        }

        // ���� dp[i][l] ���
        for (int l = 1; l <= N; l++) 
        {
            // p = 1..min(l,c[i])��ŭ v[i]�� ���� ���
            // ���� ������ l-p���� next(i)�� ���� ������ ����
            int limitP = min((long long)l, c[i]);
            long long bestVal = NEG_INF;

            for (int p = 1; p <= limitP; p++)
            {
                long long sumNow = p * x[i]; // v[i]�� p�� ���
                int rem = l - p;

                if (rem == 0)
                {
                    // �ڸ� �߰��� ���� �ʾƵ� l�� �ϼ�
                    bestVal = max(bestVal, sumNow);

                    continue;
                }

                // rem > 0 �̸�, bestNextArr[i][rem] ����
                long long tail = bestNextArr[i][rem];

                if (tail != NEG_INF) 
                {
                    bestVal = max(bestVal, sumNow + tail);
                }
            }

            dp[i][l] = bestVal;
        }
    }

    // (4) ���� ���ϱ�
    // ��� i�� ���� dp[i][N]�� �ִ��� ã�´�.
    long long answer = NEG_INF;

    for (int i = 0; i < M; i++)
    {
        answer = max(answer, dp[i][N]);
    }

    cout << (answer == NEG_INF ? -1 : answer) << "\n";

    return 0;
}