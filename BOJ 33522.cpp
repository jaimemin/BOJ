#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;

vector<bool> isComposite(MAX + 1, false);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    for (int i = 2; i * i <= MAX; i++) 
    {
        if (!isComposite[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                isComposite[j] = true;
            }
        }
    }

    vector<pair<int, int>> queries;

    for (int vertex = 1; vertex <= N; vertex++) 
    {
        if (vertex % 2 == 1)
        {
            queries.push_back({ 1, vertex });

            if (isComposite[vertex]) 
            {
                queries.push_back({ 2, vertex });
            }

            continue;
        }
        
        if (vertex != 2) 
        {
            queries.push_back({ 2, vertex });
        }
    }

    cout << queries.size() << "\n";

    for (auto query : queries)
    {
        cout << query.first << " " << query.second << "\n";
    }

    return 0;
}