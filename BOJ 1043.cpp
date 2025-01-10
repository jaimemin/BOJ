#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> parent;

int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }

    return parent[x] = find(parent[x]);
}

void merge(int x, int y) 
{
    x = find(x);
    y = find(y);

    if (x != y)
    {
        parent[y] = x;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    parent.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    int truthCount;
    cin >> truthCount;

    vector<int> truthPeople(truthCount);

    for (int i = 0; i < truthCount; i++) 
    {
        cin >> truthPeople[i];
    }

    vector<vector<int>> parties(M);

    for (int i = 0; i < M; i++) 
    {
        int partySize;
        cin >> partySize;

        parties[i].resize(partySize);

        for (int j = 0; j < partySize; j++) 
        {
            cin >> parties[i][j];
        }

        for (int j = 1; j < partySize; j++) 
        {
            merge(parties[i][0], parties[i][j]);
        }
    }

    set<int> truthRoots;

    for (int person : truthPeople) 
    {
        truthRoots.insert(find(person));
    }

    int result = 0;

    for (auto& party : parties)
    {
        bool hasTruthTeller = false;

        for (int person : party)
        {
            if (truthRoots.count(find(person)))
            {
                hasTruthTeller = true;

                break;
            }
        }

        if (!hasTruthTeller) 
        {
            ++result;
        }
    }

    cout << result << "\n";

    return 0;
}
