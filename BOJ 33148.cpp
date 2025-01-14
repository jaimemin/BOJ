#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
  �־��� multiset M(ũ�� N^2)�κ���
  ���� A(���� N, ���� ����)�� �����ϴ� �ڵ� ����.
*/

// �����÷ο� �����ϸ� �����ϴ� �Լ� (�ִ� 10^18 ���� Ȯ��)
bool safeMultiplyCheck(long long a, long long b, long long& res) 
{
    if (a > 0 && b > LLONG_MAX / a)
    {
        return false;
    }

    res = a * b;

    return true;
}

// ������ ���� �� ������ ���� ���ϱ�
// x �� ���������̸� sqrt(x) (���� ����), �ƴϸ� -1 ����
long long perfectSquareRoot(long long x)
{
    if (x < 0)
    {
        return -1;
    }

    long long r = (long long)floorl(sqrtl((long double)x));

    if ((long long)r * r == x)
    {
        return r;
    }

    if ((long long)(r + 1) * (r + 1) == x)
    {
        return r + 1;
    }

    return -1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    vector<long long> M(N * N);

    for (int i = 0; i < N * N; i++)
    {
        cin >> M[i];
    }

    sort(M.begin(), M.end());

    // Ư�� ���̽�: N=1
    if (N == 1)
    {
        // M[0] = A1*A1
        // A1 = sqrt(M[0]) �� �������� ����
        long long s = perfectSquareRoot(M[0]);

        if (s > 0) 
        {
            cout << "YES\n" << s << "\n";
        }
        else 
        {
            cout << "NO\n";
        }

        return 0;
    }

    // ���� ���� �� M[0]�� A1^2 �̾�� ��
    long long sq = M[0];
    long long A1 = perfectSquareRoot(sq);

    if (A1 <= 0) 
    {
        // �������� �ƴ�
        cout << "NO\n";

        return 0;
    }

    // multiset(�Ǵ� map)���� �� ����
    // (�ߺ��� ���� �� �����Ƿ�, long long -> long long ������ map ���)
    unordered_map<long long, long long> freq; // �ؽø�
    freq.reserve(N * N * 2ULL);
    freq.max_load_factor(0.7f);

    for (auto& x : M)
    {
        freq[x]++;
    }

    // A[1] = A1 Ȯ�� �� M���� (A1^2) �ϳ� ����
    // (i,i)�� ���� 1���� �����Ƿ� 1�� ����
    if (freq[sq] < 1)
    {
        cout << "NO\n";

        return 0;
    }

    freq[sq]--;

    if (freq[sq] == 0)
    {
        freq.erase(sq);
    }

    vector<long long> A;
    A.push_back(A1);

    // ���� A2 ~ AN�� ���ʴ�� ã��
    for (int i = 2; i <= N; i++)
    {
        if (i == 2) {
            // ���� A���� A1 �� ���� ����
            // freq���� "���� ���ŵ��� ���� ���� ���� product"�� ��
            // �װ��� A1 * A2 ��� ���� => A2 = (�� product)/A1
            // ���� �� product�� A1�� ����������� ������ NO
            // (�� ������ �Ϲ�ȭ�ؼ� i=2 ~ N���� �����ϰ� ó��)
        }

        // freq�� ��������� ���
        if (freq.empty())
        {
            cout << "NO\n";

            return 0;
        }
        // ���� freq���� ���� ���� key�� ã�� ����:  
        //   1) unordered_map�� "���� ���� key"�� ȿ�������� ������ �����
        //   2) �Ź� �ٽ� ����/�켱����ť�� ����� ��ȿ�� (�־ǿ� ����)
        // ���⼭�� map<long long,long long> (balanced tree)��
        // multiset<long long> ���� ���� ����.
        // ���� �ڵ忡���� ���ǻ� �Ź� ���� Ž���ص� N=1000, N^2=10^6�̸�
        // ����ȭ�� ���� �ð� �� ������ �� ������, �ټ� ������ �� ����.
        // �� �����ÿ��� std::map<long long,long long>�� ����.

        // ���⼭�� ���� ���� "���� ���� key"�� ã�� ���� �ϴ� ���� Ž��:
        long long smallestKey = LLONG_MAX;

        for (auto& p : freq)
        {
            if (p.first < smallestKey)
            {
                smallestKey = p.first;
            }
        }

        // smallestKey = A1 * A_i  ��� ����
        // => A_i = smallestKey / A1
        if (smallestKey % A1 != 0) 
        {
            // ����������� ������ �Ұ���
            cout << "NO\n";

            return 0;
        }

        long long Ai = smallestKey / A1;

        if (Ai <= 0)
        {
            // ���� ������ �ƴ�
            cout << "NO\n";

            return 0;
        }

        // ���� A_i�� ã������, freq����
        //   (A_i * A_j) (j=1..i)�� ��Ȯ�� Ƚ����ŭ �����ؾ� ��
        // j=i �� ���� 1�� (A_i^2)
        // j< i �� ���� 2�� (A_j*A_i �� A_i*A_j)
        // �̹� A = [A1, A2, ..., A_(i-1)] �� �ִٰ� ġ��
        // A_i^2 1�� + sum_{j=1 to i-1} 2���� ����

        // �ӽ÷� A_i �߰��ϱ�
        A.push_back(Ai);

        // �����ؾ� �ϴ� ������ ��ȸ�ϸ鼭 freq���� ����
        //   - A_k: k=1..i
        //   - product = A_k * A_i
        //   - �ʿ� ���� Ƚ��: 2 (k < i), 1 (k = i)
        // ����: ���� 10^18 �Ѿ���� �����÷� üũ
        for (int k = 1; k <= i; k++) 
        {
            long long mulVal;
            // A[k-1] == A_k  (���� �ε����� k-1)
            long long ak = A[k - 1];

            if (!safeMultiplyCheck(ak, Ai, mulVal))
            {
                // �����÷� => �����δ� M�� �� �� ���� ��
                cout << "NO\n";

                return 0;
            }

            long long needCount = (k == i ? 1LL : 2LL);

            // freq[mulVal]���� needCount��ŭ ���� ��
            if (freq.find(mulVal) == freq.end() || freq[mulVal] < needCount)
            {
                // ���� �Ұ�
                cout << "NO\n";

                return 0;
            }

            freq[mulVal] -= needCount;

            if (freq[mulVal] == 0) 
            {
                freq.erase(mulVal);
            }
        }
    }

    // ������� �Դٸ� A�� ���������� ����
    if ((int)A.size() == N) 
    {
        cout << "YES\n";

        // ���� �䱸: "������ ���� ���� ���� �ƹ��ų�"
        // ���� �������� ������ �ʿ�� ������, ���ڰ� ����ص� ����
        // ��: �׳� ���� ������� ���
        for (int i = 0; i < N; i++) 
        {
            cout << A[i] << (i + 1 < N ? ' ' : '\n');
        }
    }
    else 
    {
        cout << "NO\n";
    }

    return 0;
}
