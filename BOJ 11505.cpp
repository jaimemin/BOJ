#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<long long> segTree;

vector<long long> arr;

int n, m, k;

// init the segment tree
long long init(int node, int start, int end)
{
    if (start == end) 
    {
        return segTree[node] = arr[start] % MOD;
    }

    int mid = (start + end) / 2;

    return segTree[node] = (init(2 * node, start, mid) * init(2 * node + 1, mid + 1, end)) % MOD;
}

// Update the segment tree
long long update(int node, int start, int end, int idx, long long value)
{
    if (idx < start || idx > end)
    {
        return segTree[node];
    }

    if (start == end) 
    {
        return segTree[node] = value % MOD;
    }

    int mid = (start + end) / 2;

    return segTree[node] = (update(2 * node, start, mid, idx, value) * update(2 * node + 1, mid + 1, end, idx, value)) % MOD;
}

// Query the segment tree
long long query(int node, int start, int end, int l, int r)
{
    if (r < start || l > end)
    {
        return 1; // Multiplicative identity
    }

    if (l <= start && end <= r)
    {
        return segTree[node];
    }

    int mid = (start + end) / 2;

    return (query(2 * node, start, mid, l, r) * query(2 * node + 1, mid + 1, end, l, r)) % MOD;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;

    arr.resize(n + 1);
    segTree.resize(4 * n);

    for (int i = 1; i <= n; i++) 
    {
        cin >> arr[i];
    }

    // init the segment tree
    init(1, 1, n);

    for (int i = 0; i < m + k; i++) 
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        if (a == 1) 
        {
            // Update b-th value to c
            update(1, 1, n, b, c);
        }
        else if (a == 2) 
        {
            // Query product from b to c
            cout << query(1, 1, n, b, c) << '\n';
        }
    }

    return 0;
}
