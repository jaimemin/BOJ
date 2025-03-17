#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int getFirstJ(int p, int K, const vector<int>& jPositions) 
{
    auto it = std::lower_bound(jPositions.begin(), jPositions.end(), p);

    if (it == jPositions.end())
    {
        return jPositions.front() + K;
    }
    
    return *it;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> board(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> board[i];
    }

    int K;
    cin >> K;

    string macro;
    cin >> macro;

    vector<int> jPositions;

    for (int i = 0; i < K; i++) 
    {
        if (macro[i] == 'J')
        {
            jPositions.push_back(i);
        }
    }

    if (jPositions.empty())
    {
        cout << "NO\n";

        return 0;
    }

    vector<int> prefixA(2 * K + 1, 0);

    for (int i = 0; i < 2 * K; i++) 
    {
        prefixA[i + 1] = prefixA[i] + (macro[i % K] == 'A' ? 1 : 0);
    }

    long long total = 0;
    int p = 0;

    for (int i = 0; i < N - 1; i++) 
    {
        int obs = board[i + 1];

        if (obs == 0) 
        {
            int posJ = getFirstJ(p, K, jPositions);
            int steps = posJ - p + 1;
            total += steps;

            p = (posJ + 1) % K;
        }
        else if (obs > 0) 
        {
            int required = obs;
            int posJ = getFirstJ(p, K, jPositions);
            int cntA = prefixA[posJ] - prefixA[p];

            if (cntA < required) 
            {
                cout << "NO\n";

                return 0;
            }

            int steps = posJ - p + 1;
            total += steps;

            p = (posJ + 1) % K;
        }
        else if (obs == -1) 
        {
            if (macro[p] != 'D')
            {
                cout << "NO\n";

                return 0;
            }

            total += 1;
            p = (p + 1) % K;

            int posJ = getFirstJ(p, K, jPositions);
            int steps = posJ - p + 1;
            total += steps;

            p = (posJ + 1) % K;
        }
    }

    cout << "YES\n";

    return 0;
}