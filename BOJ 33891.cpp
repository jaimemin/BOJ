#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Edge
{
    int startIndex; 
    int speedLimit;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    long long E;
    cin >> N >> M >> E;

    vector<long long> uniquePositions;
    uniquePositions.push_back(0);
    uniquePositions.push_back(E);

    vector<long long> startPositions(N);
    vector<long long> endPositions(N);
    vector<int> speedLimits(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> startPositions[i] >> endPositions[i] >> speedLimits[i];

        uniquePositions.push_back(startPositions[i]);
        uniquePositions.push_back(endPositions[i]);
    }

    sort(uniquePositions.begin(), uniquePositions.end());
    uniquePositions.erase(unique(uniquePositions.begin(), uniquePositions.end()), uniquePositions.end());
    int nodeCount = uniquePositions.size();

    vector<vector<Edge>> finishEdges(nodeCount);

    for (int i = 0; i < N; i++) 
    {
        int a = int(lower_bound(uniquePositions.begin(), uniquePositions.end(), startPositions[i]) 
            - uniquePositions.begin());
        int b = int(lower_bound(uniquePositions.begin(), uniquePositions.end(), endPositions[i]) 
            - uniquePositions.begin());

        finishEdges[b].push_back({ a, speedLimits[i] });
    }

    vector<long double> minimumTime(nodeCount, 0.0L);
    minimumTime[0] = 0.0L;

    for (int j = 1; j < nodeCount; j++) 
    {
        long double bestTime = minimumTime[j - 1] + (uniquePositions[j] - uniquePositions[j - 1]) / (long double)M;

        for (auto edge : finishEdges[j]) 
        {
            long double candidate = minimumTime[edge.startIndex] + (uniquePositions[j] - uniquePositions[edge.startIndex]) / (long double)edge.speedLimit;

            if (candidate > bestTime) 
            {
                bestTime = candidate;
            }
        }

        minimumTime[j] = bestTime;
    }

    cout << fixed << setprecision(10) << (double)minimumTime[nodeCount - 1] << "\n";

    return 0;
}