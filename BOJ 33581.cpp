#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    // 1) K == N-1 �� ��� �Ұ���
    if (N >= 2 && K == N - 1) {
        cout << -1 << "\n";
        return 0;
    }

    // 2) K == N �� ���: ���� ���
    if (K == N) {
        for (int x = N; x >= 1; --x) {
            cout << x << (x == 1 ? '\n' : ' ');
        }
        return 0;
    }

    // 3) K <= N-2 �� ���
    //    [K, K-1, ..., 1, K+1, K+2, ..., N]
    //    (�̶� N >= 2, K <= N-2 �̹Ƿ� �׻� ���� N�� ����)
    for (int x = K; x >= 1; --x) {
        cout << x << ' ';
    }
    for (int x = K + 1; x <= N; ++x) {
        cout << x << (x == N ? '\n' : ' ');
    }

    return 0;
}
