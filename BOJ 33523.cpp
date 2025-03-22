#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 3e5 + 3e2;

typedef struct 
{
    int L, R, idx;
} Query;

int N;

int bit[MAX];

void update(int i, int delta) 
{
    for (; i <= N; i += i & -i)
    {
        bit[i] += delta;
    }
}

int query(int i) 
{
    int result = 0;

    for (; i > 0; i -= i & -i)
    {
        result += bit[i];
    }

    return result;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    vector<int> P(N + 1, 0);

    for (int i = 2; i <= N; i++) 
    {
        cin >> P[i];
    }

    int Q;
    cin >> Q;

    vector<Query> queries(Q);

    for (int i = 0; i < Q; i++)
    {
        int L, R;
        cin >> L >> R;

        queries[i] = { L, R, i };
    }

    sort(queries.begin(), queries.end(), [](const Query& a, const Query& b) {
        return a.L > b.L;
    });

    vector<pair<int, int>> events;

    for (int i = 2; i <= N; i++) 
    {
        events.push_back({ P[i], i });
    }

    sort(events.begin(), events.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });

    vector<int> answer(Q, 0);
    int ev = 0;

    for (auto q : queries) 
    {
        int curL = q.L;

        while (ev < events.size() && events[ev].first >= curL) 
        {
            int idx = events[ev].second;
            update(idx, 1);

            ev++;
        }

        int lowerBound = (curL < 2 ? 2 : curL);
        int cnt = 0;

        if (q.R >= lowerBound)
        {
            cnt = query(q.R) - query(lowerBound - 1);
        }

        answer[q.idx] = (q.R - q.L + 1) - cnt;
    }

    for (auto val : answer)
    {
        cout << val << "\n";
    }

    return 0;
}