#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    if (N == 0)
    {
        cout << 0 << " " << 0 << "\n";
        return 0;
    }

    vector<int> days(N + 1, INF);
    vector<int> water(N + 1, INF);
    days[0] = 0;
    water[0] = 0;

    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int nextDay = days[cur] + 1;

        if (cur + 1 <= N)
        {
            int newWater = water[cur] + 1;
            if (days[cur + 1] > nextDay)
            {
                days[cur + 1] = nextDay;
                water[cur + 1] = newWater;

                q.push(cur + 1);
            }
            else if (days[cur + 1] == nextDay && water[cur + 1] > newWater)
            {
                water[cur + 1] = newWater;

                q.push(cur + 1);
            }
        }

        if (cur > 0 && cur * 3 <= N)
        {
            int newVal = cur * 3;
            int newWater = water[cur] + 3;

            if (days[newVal] > nextDay)
            {
                days[newVal] = nextDay;
                water[newVal] = newWater;

                q.push(newVal);
            }
            else if (days[newVal] == nextDay && water[newVal] > newWater)
            {
                water[newVal] = newWater;

                q.push(newVal);
            }
        }

        if (cur > 1 && (long long)cur * cur <= N)
        {
            int newVal = cur * cur;
            int newWater = water[cur] + 5;
            if (days[newVal] > nextDay)
            {
                days[newVal] = nextDay;
                water[newVal] = newWater;
                q.push(newVal);
            }
            else if (days[newVal] == nextDay && water[newVal] > newWater)
            {
                water[newVal] = newWater;
                q.push(newVal);
            }
        }
    }

    cout << days[N] << " " << water[N] << "\n";

    return 0;
}