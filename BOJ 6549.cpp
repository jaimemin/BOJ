#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void func(vector<int>& heights)
{
    int n = heights.size();
    stack<int> s;
    long long maxArea = 0;

    for (int i = 0; i <= n; i++) 
    {
        while (!s.empty() && (i == n || heights[s.top()] > heights[i])) 
        {
            int h = heights[s.top()];
            s.pop();

            int width = s.empty() ? i : i - (s.top() + 1);
            maxArea = max(maxArea, (long long)h * width);
        }

        if (i < n) 
        {
            s.push(i);
        }
    }

    cout << maxArea << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            break;
        }

        vector<int> heights(n);

        for (int i = 0; i < n; i++) 
        {
            cin >> heights[i];
        }

        func(heights);
    }

    return 0;
}
