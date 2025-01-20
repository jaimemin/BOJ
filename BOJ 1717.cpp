#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

vector<int> ranks;

// Find op with path compression
int find(int x) 
{
    if (parent[x] != x) 
    {
        parent[x] = find(parent[x]); // Path compression
    }

    return parent[x];
}

// Union op with union by ranks
void merge(int a, int b) 
{
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) 
    {
        if (ranks[rootA] < ranks[rootB])
        {
            parent[rootA] = rootB;
        }
        else if (ranks[rootA] > ranks[rootB]) 
        {
            parent[rootB] = rootA;
        }
        else
        {
            parent[rootB] = rootA;

            ranks[rootA]++;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    ranks.resize(n + 1, 0);

    // Initialize each element as its own parent
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) 
    {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0) 
        {
            // Union op
            merge(a, b);
        }
        else if (op == 1) 
        {
            // Find op to check if they are in the same set
            if (find(a) == find(b))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}