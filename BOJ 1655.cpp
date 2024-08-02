#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> numbers(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> numbers[i];
    }

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int number : numbers) 
    {
        if (maxHeap.empty() || number <= maxHeap.top()) 
        {
            maxHeap.push(number);
        }
        else 
        {
            minHeap.push(number);
        }

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());

            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size()) 
        {
            maxHeap.push(minHeap.top());

            minHeap.pop();
        }

        cout << maxHeap.top() << "\n";
    }

    return 0;
}
