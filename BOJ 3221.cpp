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
        { // �������� �̵��ϴ� ���
            move = T + L - pos;

            if (move < L) 
            { // ���̰� L���� ���� ���̸� �̵��� ���
                answer.push_back(L - move);
            }
            else 
            {
                if ((move / L) % 2 == 1) 
                { // ���̰� �̵��� �Ÿ��� L�� Ȧ������� ���
                    answer.push_back(move % L);
                }
                else 
                {
                    answer.push_back(L - (move % L));
                }
            }
        }
        else 
        { // ���������� �̵��ϴ� ���
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

    sort(answer.begin(), answer.end()); // ���� ��ġ ����

    for (int pos : answer) 
    {
        cout << pos << ' ';
    }

    cout << '\n';

    return 0;
}