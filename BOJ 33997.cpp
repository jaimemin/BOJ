#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<long long> dpPrev(M, 0), dpCur(M);
    vector<long long> rowValues(M);
    vector<long long> prefixSum(M + 1);
    vector<long long> leftMin(M), rightMax(M);
    vector<long long> prefixMaxU(M), suffixMaxV(M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> rowValues[j];
        }

        prefixSum[0] = 0;

        for (int j = 0; j < M; j++)
        {
            prefixSum[j + 1] = prefixSum[j] + rowValues[j];
        }

        leftMin[0] = prefixSum[0];

        for (int j = 1; j < M; j++)
        {
            leftMin[j] = min(leftMin[j - 1], prefixSum[j]);
        }

        rightMax[M - 1] = prefixSum[M];

        for (int j = M - 2; j >= 0; j--)
        {
            rightMax[j] = max(rightMax[j + 1], prefixSum[j + 1]);
        }

        for (int j = 0; j < M; j++)
        {
            long long uVal = dpPrev[j] - leftMin[j];

            if (j == 0)
            {
                prefixMaxU[j] = uVal;
            }
            else
            {
                prefixMaxU[j] = max(prefixMaxU[j - 1], uVal);
            }
        }

        for (int j = M - 1; j >= 0; j--)
        {
            long long vVal = dpPrev[j] + rightMax[j];

            if (j == M - 1)
            {
                suffixMaxV[j] = vVal;
            }
            else
            {
                suffixMaxV[j] = max(suffixMaxV[j + 1], vVal);
            }
        }

        for (int j = 0; j < M; j++)
        {
            long long candA = prefixMaxU[j] + rightMax[j];
            long long candB = suffixMaxV[j] - leftMin[j];

            dpCur[j] = max(candA, candB);
        }

        dpPrev.swap(dpCur);
    }

    long long answer = *max_element(dpPrev.begin(), dpPrev.end());
    cout << answer << "\n";

    return 0;
}