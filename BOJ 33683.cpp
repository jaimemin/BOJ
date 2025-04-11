#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>
using namespace std;

using ll = long long;

const int kMax = 4e5 + 4e2;

ll lArr[kMax], rArr[kMax], dArr[kMax], sArr[kMax];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    if (m > n)
    {
        cout << -1 << "\n";

        return 0;
    }

    int extraProblems = n - m;
    vector<int> problemIndices;

    for (int i = 1; i <= n; i++) 
    {
        cin >> lArr[i] >> rArr[i];

        problemIndices.push_back(i);
    }

    sort(problemIndices.begin(), problemIndices.end(), [](int a, int b) {
        return lArr[a] < lArr[b];
    });

    using Pr = array<ll, 2>;
    priority_queue<Pr, vector<Pr>, greater<Pr>> minHeap;

    int nextProblemIndex = 0;
    ll currentDifficulty = 0;
    int sectionsUsed = 0;
    bool isValid = true; 

    for (int assignmentCount = 1; assignmentCount <= n; assignmentCount++) 
    {
        while (nextProblemIndex < n && lArr[problemIndices[nextProblemIndex]] <= currentDifficulty)
        {
            int idx = problemIndices[nextProblemIndex];
            minHeap.push({ rArr[idx], idx });

            nextProblemIndex++;
        }

        if (minHeap.empty())
        {
            currentDifficulty = lArr[problemIndices[nextProblemIndex]];

            while (nextProblemIndex < n && lArr[problemIndices[nextProblemIndex]] <= currentDifficulty) 
            {
                int idx = problemIndices[nextProblemIndex];
                minHeap.push({ rArr[idx], idx });

                nextProblemIndex++;
            }
        }

        Pr currentProblem = minHeap.top();
        minHeap.pop();

        ll problemR = currentProblem[0];
        int probIdx = currentProblem[1];

        if (problemR + 1 < currentDifficulty) 
        {
            isValid = false;

            break;
        }
        else if (problemR >= currentDifficulty)
        {
            dArr[probIdx] = currentDifficulty;
            currentDifficulty++;
            sectionsUsed++;
            sArr[probIdx] = min(m, sectionsUsed);
        }
        else if (problemR + 1 == currentDifficulty)
        {
            extraProblems--;

            if (extraProblems < 0) 
            {
                isValid = false;

                break;
            }

            dArr[probIdx] = currentDifficulty - 1;
            sArr[probIdx] = min(m, sectionsUsed);
        }
    }

    if (!isValid) 
    {
        cout << -1 << "\n";

        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dArr[i] << " " << sArr[i] << "\n";
    }

    return 0;
}