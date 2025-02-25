#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct 
{
    long long x, h;
} Tree;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    long long t;
    cin >> N >> t;

    vector<Tree> trees(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> trees[i].x >> trees[i].h;
    }

    // x좌표에 대해 오름차순으로 정렬
    sort(trees.begin(), trees.end(), [](const Tree& a, const Tree& b) {
        return a.x < b.x;
    });

    long long answer = 0;
    long long M = -1e18; 

    for (int i = 0; i < N; i++)
    {
        if (i == 0) 
        {
            M = max(M, trees[i].h + t * trees[i].x);

            continue;
        }

        long long lightLevel = M - t * trees[i].x;

        if (lightLevel < 0)
        {
            lightLevel = 0;
        }

        long long shadow = min(trees[i].h, lightLevel);
        answer += shadow;

        M = max(M, trees[i].h + t * trees[i].x);
    }

    cout << answer << "\n";

    return 0;
}