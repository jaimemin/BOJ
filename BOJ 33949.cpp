#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

struct segNode
{
    ll sum;
    ll maxPref;
    ll maxSuf;
    ll maxSub;
    ll minPref;
    ll minSuf;
    ll minSub;

    segNode(ll v = 0)
    {
        sum = maxPref = maxSuf = maxSub = v;
        minPref = minSuf = minSub = v;
    }
};

segNode mergeNode(const segNode& L, const segNode& R)
{
    segNode res;
    res.sum = L.sum + R.sum;

    res.maxPref = max(L.maxPref, L.sum + R.maxPref);
    res.maxSuf = max(R.maxSuf, R.sum + L.maxSuf);
    res.maxSub = max({ L.maxSub, R.maxSub, L.maxSuf + R.maxPref });

    res.minPref = min(L.minPref, L.sum + R.minPref);
    res.minSuf = min(R.minSuf, R.sum + L.minSuf);
    res.minSub = min({ L.minSub, R.minSub, L.minSuf + R.minPref });

    return res;
}

class segmentTree
{
    int n;

    vector<segNode> tree;

    void updateRec(int idx, int l, int r, int pos, ll delta)
    {
        if (l == r)
        {
            ll newVal = tree[idx].sum + delta;
            tree[idx] = segNode(newVal);

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
        {
            updateRec(idx << 1, l, mid, pos, delta);
        }
        else
        {
            updateRec(idx << 1 | 1, mid + 1, r, pos, delta);
        }

        tree[idx] = mergeNode(tree[idx << 1], tree[idx << 1 | 1]);
    }

public:
    explicit segmentTree(int size) : n(size)
    {
        tree.assign(size * 4 + 4, segNode(0));
    }

    void add(int pos, ll delta)
    {
        updateRec(1, 1, n, pos, delta);
    }

    ll circularMax()
    {
        segNode& rt = tree[1];

        if (rt.minSub == rt.sum)
        {
            return rt.maxSub;
        }

        return max(rt.maxSub, rt.sum - rt.minSub);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int S, Q;
    cin >> S >> Q;

    segmentTree seg(S);

    while (Q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int a;
            ll b;
            cin >> a >> b;

            seg.add(a, b);
        }
        else
        {
            cout << seg.circularMax() << "\n";
        }
    }

    return 0;
}