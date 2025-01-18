#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 1;

vector<int> segTreeMin, segTreeMax, arr;

int n;

// init the segment tree for minimum and maximum
void init(int node, int start, int end) 
{
    if (start == end) 
    {
        segTreeMin[node] = arr[start];
        segTreeMax[node] = arr[start];
    }
    else 
    {
        int mid = (start + end) / 2;
        init(2 * node, start, mid);
        init(2 * node + 1, mid + 1, end);

        segTreeMin[node] = min(segTreeMin[2 * node], segTreeMin[2 * node + 1]);
        segTreeMax[node] = max(segTreeMax[2 * node], segTreeMax[2 * node + 1]);
    }
}

// Query the minimum value in range [l, r]
int queryMin(int node, int start, int end, int l, int r) 
{
    if (r < start || end < l)
    {
        return INF;  // Out of range
    }

    if (l <= start && end <= r)
    {
        return segTreeMin[node];  // Completely inside range
    }

    int mid = (start + end) / 2;

    return min(queryMin(2 * node, start, mid, l, r), queryMin(2 * node + 1, mid + 1, end, l, r));
}

// Query the maximum value in range [l, r]
int queryMax(int node, int start, int end, int l, int r) 
{
    if (r < start || end < l)
    {
        return -INF;  // Out of range
    }

    if (l <= start && end <= r)
    {
        return segTreeMax[node];  // Completely inside range
    }

    int mid = (start + end) / 2;

    return max(queryMax(2 * node, start, mid, l, r), queryMax(2 * node + 1, mid + 1, end, l, r));
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> n >> m;

    arr.resize(n + 1);
    segTreeMin.resize(4 * n, INF);
    segTreeMax.resize(4 * n, -INF);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    init(1, 1, n);

    while (m--) 
    {
        int a, b;
        cin >> a >> b;

        int minValue = queryMin(1, 1, n, a, b);
        int maxValue = queryMax(1, 1, n, a, b);

        cout << minValue << ' ' << maxValue << '\n';
    }

    return 0;
}