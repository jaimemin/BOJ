#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// freq[x] == 0 �� �ƴ� 'x'�� ������ �����ϱ� ���� ���� ���� �����
// �ڵ忡���� static ����/�Լ� �� ���� ���������� �����մϴ�.

// freq[x] ���� �����ϸ鼭 mismatchCount�� �������ִ� �Լ�
//  - d > 0 �̸� "���� ������ ���� x�� d�� �߰�" (freq[x] += d)
//  - d < 0 �̸� "������ ������ ���� x�� -d�� �߰�"�� ���� ȿ�� (freq[x] -= |d|)
//
// freq[x]�� 0���� d�� �ٲ�� mismatchCount�� 1 ����
// freq[x]�� d���� 0���� �ٲ�� mismatchCount�� 1 ����
void updateFreq(vector<int>& freq, int& mismatchCount, int x, int d) 
{
    int oldVal = freq[x];
    int newVal = oldVal + d;
    freq[x] = newVal;

    // oldVal == 0 �̾��µ� newVal != 0 �� �� ��� => mismatchCount++
    if (oldVal == 0 && newVal != 0)
    {
        mismatchCount++;
    }
    // oldVal != 0 �̾��µ� newVal == 0 �� �� ��� => mismatchCount--
    else if (oldVal != 0 && newVal == 0)
    {
        mismatchCount--;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<long long> A(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }

    // == ��ǥ ���� ==
    // 1) copy & sort & unique
    vector<long long> comp = A;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    // 2) �Լ� getID
    auto getID = [&](long long x)
    {
        // lower_bound �� ��ġ ã��
        return int(std::lower_bound(comp.begin(), comp.end(), x) - comp.begin());
    };
    // ���� A�� ���� ������ ��ü
    for (int i = 0; i < N; i++)
    {
        A[i] = getID(A[i]);
    }

    // ����� ���� �ִ� + 1 = comp.size()
    int distinctCount = (int)comp.size();

    int ans = 0;  // ���� �����ϴ� �ִ� ¦�� ����

    // i �� i+1 ���̸� "��� ���"�� ��´� (0-based ����)
    // => �ʱ� ������ [i, i+1]
    // => ���� 2���� �����ؼ� �¿�� Ȯ���� ������ 2�� ����
    for (int i = 0; i < N - 1; i++)
    {
        // freq[x] = ���� ���� ���� - ������ ���� ����
        // ���� 0�̸� ��=������ ��Ƽ�� ����
        vector<int> freq(distinctCount, 0);
        int mismatchCount = 0;

        // �ʱ� ����: [i, i+1] (���� 2)
        // ���� ������ A[i], ������ ������ A[i+1]�� �ִٰ� ����:
        updateFreq(freq, mismatchCount, A[i], +1);
        updateFreq(freq, mismatchCount, A[i + 1], -1);

        // ���� mismatchCount == 0�̸� ����=2 �������� �̹� ����
        if (mismatchCount == 0)
        {
            ans = max(ans, 2);
        }

        // �¿�� Ȯ��
        int left = i, right = i + 1;

        while (left > 0 && right < N - 1)
        {
            left--;   // �� ĭ ���� Ȯ��
            right++;  // �� ĭ ������ Ȯ��
            // ���Ӱ� ���Ե� ���� ����
            updateFreq(freq, mismatchCount, A[left], +1);
            // ���Ӱ� ���Ե� ������ ����
            updateFreq(freq, mismatchCount, A[right], -1);

            if (mismatchCount == 0)
            {
                int length = (right - left + 1); // ���� ���� ����

                ans = max(ans, length);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}