#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> cranes(N);

    for (int i = 0; i < N; i++)
    {
        cin >> cranes[i];
    }

    int M;
    cin >> M;

    vector<int> boxes(M);

    for (int i = 0; i < M; i++) 
    {
        cin >> boxes[i];
    }

    sort(cranes.begin(), cranes.end(), greater<int>());
    sort(boxes.begin(), boxes.end(), greater<int>());

    if (boxes[0] > cranes[0])
    {
        cout << -1 << "\n";

        return 0;
    }

    vector<int> pos(N, 0);
    vector<bool> checked(M, false);

    int time = 0;
    int count = 0;

    while (count < M) 
    {
        for (int i = 0; i < N; i++)
        {
            while (pos[i] < M)
            {
                if (!checked[pos[i]] && cranes[i] >= boxes[pos[i]])
                {
                    checked[pos[i]] = true;
                    pos[i]++; 
                    count++;

                    break;
                }

                pos[i]++;
            }
        }

        time++;
    }

    cout << time << "\n";

    return 0;
}