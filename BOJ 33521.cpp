#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 6e6;

struct Node 
{
    int left, right;
    int cnt;
    long long sum;
};

Node seg[MAX];
int segSize = 0;

int newNode(int l, int r, int cnt, long long sum)
{
    seg[++segSize] = { l, r, cnt, sum };

    return segSize;
}

int build(int start, int end) 
{
    int idx = newNode(0, 0, 0, 0);

    if (start == end)
    {
        return idx;
    }

    int mid = (start + end) / 2;
    int leftChild = build(start, mid);
    int rightChild = build(mid + 1, end);
    seg[idx].left = leftChild;
    seg[idx].right = rightChild;

    return idx;
}

int update(int prev, int start, int end, int pos, long long value)
{
    int idx = newNode(seg[prev].left, seg[prev].right, seg[prev].cnt, seg[prev].sum);

    if (start == end)
    {
        seg[idx].cnt += 1;
        seg[idx].sum += value;

        return idx;
    }

    int mid = (start + end) / 2;

    if (pos <= mid)
    {
        int leftChild = update(seg[prev].left, start, mid, pos, value);
        seg[idx].left = leftChild;
    }
    else 
    {
        int rightChild = update(seg[prev].right, mid + 1, end, pos, value);
        seg[idx].right = rightChild;
    }

    seg[idx].cnt = seg[seg[idx].left].cnt + seg[seg[idx].right].cnt;
    seg[idx].sum = seg[seg[idx].left].sum + seg[seg[idx].right].sum;

    return idx;
}

long long querySmallest(int idx, int start, int end, int k, vector<int>& v) 
{
    if (k == 0)
    {
        return 0;
    }

    if (start == end) 
    {
        return (long long)k * v[start - 1];
    }

    int mid = (start + end) / 2;
    int leftCount = seg[seg[idx].left].cnt;

    if (k <= leftCount)
    {
        return querySmallest(seg[idx].left, start, mid, k, v);
    }

    return seg[seg[idx].left].sum + querySmallest(seg[idx].right, mid + 1, end, k - leftCount, v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<pair<int, int>> equipments(N);

    for (int i = 0; i < N; i++) 
    {
        int A, B;
        cin >> A >> B;

        equipments[i] = { A, B };
    }

    sort(equipments.begin(), equipments.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first == p2.first)
        {
            return p1.second < p2.second;
        }

        return p1.first < p2.first;
    });

    vector<int> sortedA(N), sortedB(N);

    for (int i = 0; i < N; i++) 
    {
        sortedA[i] = equipments[i].first;
        sortedB[i] = equipments[i].second;
    }

    vector<long long> prefixA(N + 1, 0);

    for (int i = 0; i < N; i++) 
    {
        prefixA[i + 1] = prefixA[i] + sortedA[i];
    }

    vector<int> comp = sortedB;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    int M = comp.size();

    vector<int> compIndex(N);

    for (int i = 0; i < N; i++) 
    {
        compIndex[i] = int(lower_bound(comp.begin(), comp.end(), sortedB[i]) - comp.begin()) + 1;
    }

    segSize = 0;
    int baseRoot = build(1, M);
    vector<int> persRoot(N + 1, 0);
    persRoot[0] = baseRoot;

    for (int i = 0; i < N; i++) 
    {
        persRoot[i + 1] = update(persRoot[i], 1, M, compIndex[i], sortedB[i]);
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        long long X, Y;
        cin >> X >> Y;

        int low = 0, high = N;

        while (low < high) 
        {
            int mid = (low + high + 1) / 2;

            if (prefixA[mid] > X) 
            {
                high = mid - 1;

                continue;
            }

            long long extraGold = X - prefixA[mid];
            int needStone = (mid > extraGold) ? mid - (int)extraGold : 0;
            long long stoneCost = (needStone > 0 ? querySmallest(persRoot[mid], 1, M, needStone, comp) : 0);

            if (stoneCost <= Y)
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << low << "\n";
    }

    return 0;
}