#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAX = 500 + 5;

int N;

int cache[MAX][MAX];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    vector<pair<int, int>> matrices(N);

    for (int i = 0; i < N; ++i) 
    {
        cin >> matrices[i].first >> matrices[i].second;
    }

    for (int len = 1; len < N; len++) 
    {
        for (int i = 0; i < N - len; i++) 
        {
            int j = i + len;
            cache[i][j] = INT_MAX;

            for (int k = i; k < j; k++) 
            {
                int cost = cache[i][k] + cache[k + 1][j] + matrices[i].first * matrices[k].second * matrices[j].second;

                cache[i][j] = min(cache[i][j], cost);
            }
        }
    }

    cout << cache[0][N - 1] << "\n";

    return 0;
}
