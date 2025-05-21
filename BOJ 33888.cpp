#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int N;

bool isReachable(int s, int t, vector<bool>& isCore, vector<vector<int>> &adj)
{
    vector<bool> visited(N + 1, false);
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == t)
        {
            return true;
        }

        for (int w : adj[u])
        {
            if (visited[w])
            {
                continue;
            }

            if (isCore[w] && w != s && w != t)
            {
                continue;
            }

            visited[w] = true;
            q.push(w);
        }
    }

    return false;
}

void add(int x, int y, set<pair<int, int>> &target)
{
    if (x > y)
    {
        swap(x, y);
    }

    target.insert({ x,y });
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < N + 3; i++) 
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> deg(N + 1);

    for (int i = 1; i <= N; i++)
    {
        deg[i] = adj[i].size();
    }

    vector<int> candsF, candsMid3, candsHigh4;

    for (int i = 1; i <= N; i++)
    {
        if (deg[i] == 1)
        {
            candsF.push_back(i);
        }
        else if (deg[i] == 3)
        {
            candsMid3.push_back(i);
        }
        else if (deg[i] == 4)
        {
            candsHigh4.push_back(i);
        }
    }

    int F = candsF[0];

    for (int idxC = 0; idxC < 2; idxC++)
    {
        int C = candsHigh4[idxC];
        int E = candsHigh4[1 - idxC];

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++) 
            {
                if (j == i)
                {
                    continue;
                }

                int k = 3 - i - j;
                int A = candsMid3[i];
                int B = candsMid3[j];
                int D = candsMid3[k];

                if (!(D > B))
                {
                    continue;
                }

                vector<bool> isCore(N + 1, false);
                isCore[A] = true;
                isCore[B] = true;
                isCore[C] = true;
                isCore[D] = true;
                isCore[E] = true; 
                isCore[F] = true;

                set<pair<int, int>> target;
                add(A, B, target); 
                add(A, C, target);
                add(A, D, target);
                add(B, C, target);
                add(B, E, target);
                add(C, D, target);
                add(C, E, target);
                add(D, E, target);
                add(E, F, target);

                vector<int> cores = { A,B,C,D,E,F };
                set<pair<int, int>> reach;

                for (int p = 0; p < 6; p++)
                {
                    for (int q = p + 1; q < 6; q++)
                    {
                        int u = cores[p], v = cores[q];

                        if (isReachable(u, v, isCore, adj))
                        {
                            int x = u;
                            int y = v;

                            if (x > y)
                            {
                                swap(x, y);
                            }

                            reach.insert({ x,y });
                        }
                    }
                }

                if (reach == target)
                {
                    cout << A << " "
                        << B << " "
                        << C << " "
                        << D << " "
                        << E << " "
                        << F << "\n";

                    return 0;
                }
            }
        }
    }

    return 0;
}