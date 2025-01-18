#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L, T, N;
    cin >> L >> T >> N;

    vector<int> answer;

    for (int i = 0; i < N; i++) 
    {
        int pos;
        char dir;
        cin >> pos >> dir;

        int move;

        if (dir == 'L')
        { // 왼쪽으로 이동하는 경우
            move = T + L - pos;

            if (move < L) 
            { // 개미가 L보다 작은 길이를 이동한 경우
                answer.push_back(L - move);
            }
            else 
            {
                if ((move / L) % 2 == 1) 
                { // 개미가 이동한 거리가 L의 홀수배수일 경우
                    answer.push_back(move % L);
                }
                else 
                {
                    answer.push_back(L - (move % L));
                }
            }
        }
        else 
        { // 오른쪽으로 이동하는 경우
            move = T + pos;

            if (move < L) 
            {
                answer.push_back(move);
            }
            else 
            {
                if ((move / L) % 2 == 1) 
                {
                    answer.push_back(L - (move % L));
                }
                else 
                {
                    answer.push_back(move % L);
                }
            }
        }
    }

    sort(answer.begin(), answer.end()); // 최종 위치 정렬

    for (int pos : answer) 
    {
        cout << pos << ' ';
    }

    cout << '\n';

    return 0;
}