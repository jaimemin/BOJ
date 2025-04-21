#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int N;

vector<int> aVec, bVec, cVec;

vector<int> bInv, cInv;

vector<int> fVec, gVec;

vector<vector<int>> treeAdj;

vector<int> timeInVec, timeOutVec, subTreeSize;

int timer;

vector<int> orbitIdVec;

vector<bool> orbitVisited;

vector<int> orbitMinVec, orbitMaxVec;

vector<int> lVal, rVal;

struct Candidate 
{
    int timeIn, timeOut, size;
};

vector<Candidate> candidatesVec;

void treeDfs(int cur, int parent)
{
    timeInVec[cur] = ++timer;
    subTreeSize[cur] = 1;

    for (int nxt : treeAdj[cur])
    {
        if (nxt == parent)
        {
            continue;
        }

        treeDfs(nxt, cur);
        subTreeSize[cur] += subTreeSize[nxt];
    }

    timeOutVec[cur] = timer;
}

void computeOrbits()
{
    orbitIdVec.assign(N + 1, 0);
    orbitVisited.assign(N + 1, false);
    orbitMinVec.assign(N + 1, 0);
    orbitMaxVec.assign(N + 1, 0);
    int curOrbit = 0;

    for (int i = 1; i <= N; i++) 
    {
        if (!orbitVisited[i])
        {
            curOrbit++;
            queue<int> q;
            q.push(i);

            orbitVisited[i] = true;
            orbitIdVec[i] = curOrbit;
            orbitMinVec[curOrbit] = timeInVec[i];
            orbitMaxVec[curOrbit] = timeInVec[i];

            while (!q.empty()) 
            {
                int curVertex = q.front();
                q.pop();
                int nb = fVec[curVertex];

                if (!orbitVisited[nb])
                {
                    orbitVisited[nb] = true;
                    orbitIdVec[nb] = curOrbit;

                    q.push(nb);

                    orbitMinVec[curOrbit] = min(orbitMinVec[curOrbit], timeInVec[nb]);
                    orbitMaxVec[curOrbit] = max(orbitMaxVec[curOrbit], timeInVec[nb]);
                }

                nb = gVec[curVertex];

                if (!orbitVisited[nb]) 
                {
                    orbitVisited[nb] = true;
                    orbitIdVec[nb] = curOrbit;

                    q.push(nb);

                    orbitMinVec[curOrbit] = min(orbitMinVec[curOrbit], timeInVec[nb]);
                    orbitMaxVec[curOrbit] = max(orbitMaxVec[curOrbit], timeInVec[nb]);
                }
            }
        }
    }
}

void computeLr(int cur, int parent)
{
    int orb = orbitIdVec[cur];
    lVal[cur] = orbitMinVec[orb];
    rVal[cur] = orbitMaxVec[orb];

    for (int nxt : treeAdj[cur]) 
    {
        if (nxt == parent)
        {
            continue;
        }

        computeLr(nxt, cur);
        lVal[cur] = min(lVal[cur], lVal[nxt]);
        rVal[cur] = max(rVal[cur], rVal[nxt]);
    }
}

struct SegmentTree 
{
    int n;
    vector<int> seg;

    SegmentTree(int n) : n(n)
    {
        seg.assign(2 * n, INF);
    }

    void build(vector<int>& arr) 
    {
        for (int i = 0; i < n; i++)
        {
            seg[n + i] = arr[i];
        }

        for (int i = n - 1; i > 0; i--)
        {
            seg[i] = min(seg[2 * i], seg[2 * i + 1]);
        }
    }

    int query(int l, int r) 
    {
        int result = INF;

        for (l += n, r += n; l < r; l /= 2, r /= 2) 
        {
            if (l & 1)
            {
                result = min(result, seg[l]);

                l++;
            }

            if (r & 1)
            {
                r--;

                result = min(result, seg[r]);
            }
        }

        return result;
    }
};

int lowerBoundByTimeInGreaterThan(const vector<Candidate>& vec, int key)
{
    int low = 0, high = (int)vec.size();
    int pos = vec.size();

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (vec[mid].timeIn > key) 
        {
            pos = mid;

            high = mid;
        }
        else 
        {
            low = mid + 1;
        }
    }

    return pos;
}

int lowerBoundByTimeInAtLeast(const vector<Candidate>& vec, int key) 
{
    int low = 0, high = (int)vec.size();
    int pos = vec.size();

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (vec[mid].timeIn >= key) 
        {
            pos = mid;

            high = mid;
        }
        else 
        {
            low = mid + 1;
        }
    }

    return pos;
}

int m;

bool checkX(int X, int totalN) 
{
    vector<int> arr(m, INF);
    bool nonNestedAvailable = false;

    for (int i = 0; i < m; i++) 
    {
        int sz = candidatesVec[i].size;

        if (sz >= X && sz <= totalN - 2 * X)
        {
            arr[i] = sz;

            nonNestedAvailable = true;
        }
        else
        {
            arr[i] = INF;
        }
    }

    if (nonNestedAvailable) 
    {
        SegmentTree seg(m);
        seg.build(arr);

        for (int i = 0; i < m; i++)
        {
            if (arr[i] == INF)
            {
                continue;
            }

            int target = candidatesVec[i].timeOut;
            int pos = lowerBoundByTimeInGreaterThan(candidatesVec, target);

            if (pos < m)
            {
                int minVal = seg.query(pos, m);

                if (minVal != INF && arr[i] + minVal <= totalN - X)
                {
                    return true;
                }
            }
        }
    }

    vector<int> arrNest(m, INF);
    bool nestedAvailable = false;

    for (int i = 0; i < m; i++)
    {
        int sz = candidatesVec[i].size;

        if (sz >= X && sz <= totalN - X) 
        {
            arrNest[i] = sz;
            nestedAvailable = true;
        }
        else 
        {
            arrNest[i] = INF;
        }
    }

    if (nestedAvailable) 
    {
        SegmentTree seg(m);
        seg.build(arrNest);

        for (int i = 0; i < m; i++) 
        {
            if (arrNest[i] == INF)
            {
                continue;
            }

            int szOuter = arrNest[i];
            int lowertimeIn = candidatesVec[i].timeIn + 1;
            int uppertimeIn = candidatesVec[i].timeOut;
            int posL = lowerBoundByTimeInAtLeast(candidatesVec, lowertimeIn);
            int posR = lowerBoundByTimeInGreaterThan(candidatesVec, uppertimeIn);

            if (posL < posR) 
            {
                int minVal = seg.query(posL, posR);

                if (minVal != INF && szOuter - minVal >= X)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--) 
    {
        cin >> N;
        aVec.resize(N + 1);
        bVec.resize(N + 1);
        cVec.resize(N + 1);

        for (int i = 1; i <= N; i++) 
        {
            cin >> aVec[i];
        }

        for (int i = 1; i <= N; i++)
        {
            cin >> bVec[i];
        }

        for (int i = 1; i <= N; i++) 
        {
            cin >> cVec[i];
        }

        bInv.assign(N + 1, 0);
        cInv.assign(N + 1, 0);

        for (int i = 1; i <= N; i++) 
        {
            bInv[bVec[i]] = i;
            cInv[cVec[i]] = i;
        }

        fVec.resize(N + 1);
        gVec.resize(N + 1);

        for (int i = 1; i <= N; i++) 
        {
            fVec[i] = bInv[aVec[i]];
            gVec[i] = cInv[aVec[i]];
        }

        treeAdj.assign(N + 1, vector<int>());

        for (int i = 1; i < N; i++) 
        {
            int u, v;
            cin >> u >> v;

            treeAdj[u].push_back(v);
            treeAdj[v].push_back(u);
        }

        timeInVec.assign(N + 1, 0);
        timeOutVec.assign(N + 1, 0);
        subTreeSize.assign(N + 1, 0);
        timer = 0;

        treeDfs(1, 0);
        computeOrbits();

        lVal.assign(N + 1, 0);
        rVal.assign(N + 1, 0);
        computeLr(1, 0);

        candidatesVec.clear();

        for (int v = 2; v <= N; v++) 
        {
            if (lVal[v] == timeInVec[v] && rVal[v] <= timeOutVec[v])
            {
                Candidate cand;
                cand.timeIn = timeInVec[v];
                cand.timeOut = timeOutVec[v];
                cand.size = subTreeSize[v];

                candidatesVec.push_back(cand);
            }
        }

        sort(candidatesVec.begin(), candidatesVec.end(), [](const Candidate& c1, const Candidate& c2) {
            return c1.timeIn < c2.timeIn;
         });

        m = (int)candidatesVec.size();

        int answer = 0;
        int low = 1, high = N / 3;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (checkX(mid, N))
            {
                answer = mid;

                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (answer == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << answer << "\n";
        }
    }

    return 0;
}