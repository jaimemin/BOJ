#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, H;
    cin >> N >> H;

    vector<int> bottom(H + 1, 0); // ����
    vector<int> top(H + 1, 0);    // ������

    for (int i = 0; i < N; i++) 
    {
        int height;
        cin >> height;

        if (i % 2 == 0)
        {
            bottom[height]++;
        }
        else 
        {
            top[height]++;
        }
    }

    // ���� �� ���
    for (int i = H - 1; i >= 1; i--) 
    {
        bottom[i] += bottom[i + 1];
        top[i] += top[i + 1];
    }

    int minObstacles = N; // �ּڰ� �ʱ�ȭ
    int count = 0;        // �ּڰ� ������ ����

    for (int i = 1; i <= H; i++) 
    {
        int obstacles = bottom[i] + top[H - i + 1];

        if (obstacles < minObstacles) 
        {
            minObstacles = obstacles;
            count = 1;
        }
        else if (obstacles == minObstacles)
        {
            count++;
        }
    }

    cout << minObstacles << " " << count << "\n";

    return 0;
}