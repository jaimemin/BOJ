#include <iostream>
using namespace std;

/**
 * ���� ���� (�Ǵ� main ���ο��� static ���)
 *  - N, K �ִ� 500,000���� ����
 *  - Ai �ִ� 10^9���� ����
 */
const int MAXN = 500000;

int N, K;

int A[MAXN];

/**
 * @brief
 *  X�� "���� AND ��"���� ��������(��, ��� ���� ���ҵ��� X�� ��� ��Ʈ�� �����ϵ��� ���� �� �ִ���)
 *  �׸����ϰ� �˻��ϴ� �Լ�.
 *
 * @param X  �ĺ��� �˻��� ����
 * @return �����ϸ� true, �Ұ����ϸ� false
 */
bool feasible(long long X) 
{
    long long aggregator = 0;
    int segmentCount = 0;      // ������� ���׸�Ʈ(��ȿ ����) ����

    for (int i = 0; i < N; i++) 
    {
        aggregator |= A[i];
        // ��������� OR�� X�� �䱸�ϴ� ��� ��Ʈ�� �����ϸ� ���׸�Ʈ 1�� �ϼ�
        if ((aggregator & X) == X)
        {
            segmentCount++;

            aggregator = 0; // ���� ���׸�Ʈ�� ���� ����
        }
    }

    // ���׸�Ʈ�� �ִ��� ���� ������� �� segmentCount = S
    // ���� Ƚ�� = N - S
    // "������ �ִ� K������ �� �� �ִ�" = "S�� �ּ� (N-K) �̻��� �Ǿ�� �Ѵ�."
    return (segmentCount >= (N - K));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    long long answer = 0LL;

    // �ִ� 10^9 �̹Ƿ� 30��Ʈ(2^30=1073741824) ���������� Ȯ���ϸ� ���
    // 31��Ʈ���� �ᵵ ���� ����
    for (int bit = 30; bit >= 0; bit--) 
    {
        long long testCandidate = answer | (1LL << bit);

        if (feasible(testCandidate))
        {
            answer = testCandidate;
        }
    }

    cout << answer << "\n";

    return 0;
}
