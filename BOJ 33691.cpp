#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
    return a.first > b.first;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    unordered_map<string, int> lastUsage;

    for (int i = 1; i <= N; i++) 
    {
        string s;
        cin >> s;

        lastUsage[s] = i;
    }

    int K;
    cin >> K;

    unordered_set<string> pinnedSet;

    for (int i = 0; i < K; i++) 
    {
        string s;
        cin >> s;

        pinnedSet.insert(s);
    }

    vector<pair<int, string>> pinned;
    vector<pair<int, string>> unpinned;

    for (auto entry : lastUsage)
    {
        if (pinnedSet.find(entry.first) != pinnedSet.end()) 
        {
            pinned.push_back({ entry.second, entry.first });
        }
        else
        {
            unpinned.push_back({ entry.second, entry.first });
        }
    }

    sort(pinned.begin(), pinned.end(), cmp);
    sort(unpinned.begin(), unpinned.end(), cmp);

    for (auto p : pinned)
    {
        cout << p.second << "\n";
    }

    for (auto p : unpinned) 
    {
        cout << p.second << "\n";
    }

    return 0;
}