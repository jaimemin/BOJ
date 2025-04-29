#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXM = 100000;

long long tree[4 * MAXM];

bool lazyClear[4 * MAXM];

int M;  // Number of walls

void init(int p, int l, int r)
{
    tree[p] = 0;
    lazyClear[p] = true;
}

void pushDown(int p, int l, int r) 
{
    if (lazyClear[p] && l < r) 
    {
        int m = (l + r) / 2;
        init(p * 2, l, m);
        init(p * 2 + 1, m + 1, r);
        lazyClear[p] = false;
    }
}

void build(int p, int l, int r, const vector<long long>& v)
{
    lazyClear[p] = false;

    if (l == r) 
    {
        tree[p] = v[l];
    }
    else
    {
        int m = (l + r) / 2;
        build(p * 2, l, m, v);
        build(p * 2 + 1, m + 1, r, v);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
}

long long query(int p, int l, int r, int i, int j)
{
    if (i > r || j < l)
    {
        return 0;
    }

    if (i <= l && r <= j)
    {
        return tree[p];
    }
    
    pushDown(p, l, r);
    int m = (l + r) / 2;

    return query(p * 2, l, m, i, j) + query(p * 2 + 1, m + 1, r, i, j);
}

void clear(int p, int l, int r, int i, int j)
{
    if (i > r || j < l)
    {
        return;
    }

    if (i <= l && r <= j) 
    {
        init(p, l, r);

        return;
    }

    pushDown(p, l, r);
    int m = (l + r) / 2;
    
    clear(p * 2, l, m, i, j);
    clear(p * 2 + 1, m + 1, r, i, j);
    
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
}

long long queryWalls(int i, int j) 
{
    if (i > j || M == 0)
    {
        return 0;
    }

    return query(1, 0, M - 1, i, j);
}

void clearWalls(int i, int j)
{
    if (i > j || M == 0)
    {
        return;
    }

    clear(1, 0, M - 1, i, j);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> M >> Q;

    vector<pair<int, long long>> walls;
 
    for (int i = 0; i < M; i++)
    {
        int w;
        long long d;
        cin >> w >> d;

        walls.emplace_back(w, d);
    }

    sort(walls.begin(), walls.end());

    vector<int> pos(M);
    vector<long long> dur(M);

    for (int i = 0; i < M; i++)
    {
        pos[i] = walls[i].first;
        dur[i] = walls[i].second;
    }

    if (M > 0)
    {
        build(1, 0, M - 1, dur);
    }

    for (int i = 0; i < Q; i++) 
    {
        int P;
        cin >> P;

        int idx = int(lower_bound(pos.begin(), pos.end(), P) - pos.begin());
        long long strokesLeft = queryWalls(0, idx - 1);
        long long strokesRight = queryWalls(idx, M - 1);
        int distLeft = P - 1;
        int distRight = N - P;
        bool chooseLeft;

        if (strokesLeft < strokesRight) 
        {
            chooseLeft = true;
        }
        else if (strokesLeft > strokesRight)
        {
            chooseLeft = false;
        }
        else
        {
            if (distLeft < distRight)
            {
                chooseLeft = true;
            }
            else if (distLeft > distRight)
            {
                chooseLeft = false;
            }
            else
            {
                chooseLeft = true;
            }
        }

        cout << (chooseLeft ? strokesLeft : strokesRight) << "\n";

        if (chooseLeft)
        {
            clearWalls(0, idx - 1);
        }
        else
        {
            clearWalls(idx, M - 1);
        }
    }

    return 0;
}