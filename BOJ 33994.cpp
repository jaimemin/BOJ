#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    if (N % 2 == 0)
    {
        cout << "No\n";

        return 0;
    }

    cout << "Yes\n";

    int Np = N + 1;
    int dummy = Np;
    vector<int> players(Np);

    for (int i = 0; i < Np; i++) 
    {
        players[i] = i + 1;
    }

    vector<vector<pair<int, int>>> M(3);

    for (int r = 0; r < 3; r++) 
    {
        for (int i = 0; i < Np / 2; i++) 
        {
            int u = players[i];
            int v = players[Np - 1 - i];

            if (u == dummy || v == dummy)
            {
                continue;
            }

            if (u > v)
            {
                swap(u, v);
            }

            M[r].emplace_back(u, v);
        }

        int tmp = players[Np - 1];

        for (int i = Np - 1; i > 1; i--) 
        {
            players[i] = players[i - 1];
        }

        players[1] = tmp;
    }

    vector<vector<pair<int, int>>> T(3);
    T[0].reserve(N - 1);
    T[1].reserve(N - 1);
    T[2].reserve(N - 1);

    for (auto e : M[1])
    {
        T[0].push_back(e);
    }

    for (auto e : M[2])
    {
        T[0].push_back(e);
    }

    for (auto e : M[0])
    {
        T[1].push_back(e);
    }

    for (auto e : M[2])
    {
        T[1].push_back(e);
    }

    for (auto e : M[0])
    {
        T[2].push_back(e);
    }

    for (auto e : M[1])
    {
        T[2].push_back(e);
    }

    for (int t = 0; t < 3; t++) 
    {
        for (auto e : T[t]) 
        {
            cout << e.first << ' ' << e.second << "\n";
        }
    }

    return 0;
}