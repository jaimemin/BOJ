#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1024;

int n;

vector<vector<int>> tree;

vector<vector<int>> grid;

// Update the Fenwick Tree at (x, y) with value `delta`
void update(int x, int y, int delta)
{
    for (int i = x; i <= n; i += (i & -i))
    {
        for (int j = y; j <= n; j += (j & -j)) 
        {
            tree[i][j] += delta;
        }
    }
}

// Query the sum from (1, 1) to (x, y)
int query(int x, int y)
{
    int sum = 0;

    for (int i = x; i > 0; i -= (i & -i))
    {
        for (int j = y; j > 0; j -= (j & -j)) 
        {
            sum += tree[i][j];
        }
    }

    return sum;
}

// Query the sum in the rectangle defined by (x1, y1) to (x2, y2)
int rangeQuery(int x1, int y1, int x2, int y2)
{
    return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M;
    cin >> n >> M;

    tree.assign(n + 1, vector<int>(n + 1, 0));
    grid.assign(n + 1, vector<int>(n + 1, 0));

    // Read the initial grid and build the Fenwick Tree
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];

            update(i, j, grid[i][j]);
        }
    }

    // Process queries
    while (M--)
    {
        int w;
        cin >> w;

        if (w == 0)
        { // Update operation
            int x, y, c;
            cin >> x >> y >> c;

            int delta = c - grid[x][y];
            grid[x][y] = c;

            update(x, y, delta);
        }
        else if (w == 1)
        { // Range query operation
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            cout << rangeQuery(x1, y1, x2, y2) << '\n';
        }
    }

    return 0;
}
