#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX_N = 50;

const int MAX_NUM = 1000;

const int MAX_SUM = 2000;

int N;

int nums[MAX_N];

bool isPrime[MAX_SUM + 1];

vector<int> graph[MAX_N];

int match[MAX_N];

bool visited[MAX_N];

void eratosthenes() 
{
    fill(isPrime, isPrime + MAX_SUM + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX_SUM; i++) 
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX_SUM; j += i) 
            {
                isPrime[j] = false;
            }
        }
    }
}

bool func(int u) 
{
    for (int v : graph[u]) 
    {
        if (!visited[v])
        {
            visited[v] = true;

            if (match[v] == -1 || func(match[v]))
            {
                match[v] = u;

                return true;
            }
        }
    }

    return false;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    vector<int> odds, evens;

    for (int i = 0; i < N; i++) 
    {
        cin >> nums[i];
    }

    eratosthenes();

    set<int> candidates;

    for (int i = 1; i < N; i++) 
    {
        if (!isPrime[nums[0] + nums[i]])
        {
            continue;
        }

        // 첫 번째 수와 nums[i]를 짝으로 고정
        odds.clear();
        evens.clear();

        for (int j = 1; j < N; j++) 
        {
            if (i == j)
            {
                continue;
            }

            nums[j] % 2 == 0 ? evens.push_back(j) : odds.push_back(j);
        }

        if (odds.size() != evens.size())
        {
            continue;
        }

        for (int j = 0; j < N; j++)
        {
            graph[j].clear();
        }

        // 간선 연결
        for (int u : odds) 
        {
            for (int v : evens) 
            {
                if (isPrime[nums[u] + nums[v]]) 
                {
                    graph[u].push_back(v);
                }
            }
        }

        memset(match, -1, sizeof(match));
        int matchCount = 0;

        // 각 홀수 노드에 대해 매칭 시도
        for (int u : odds) 
        {
            memset(visited, false, sizeof(visited));

            if (func(u))
            {
                matchCount++;
            }
        }

        if (matchCount == odds.size()) 
        {
            candidates.insert(nums[i]);
        }
    }

    if (candidates.empty()) 
    {
        cout << -1 << "\n";

        return 0;
    }

    for (int candidate : candidates) 
    {
        cout << candidate << " ";
    }

    cout << "\n";

    return 0;
}
