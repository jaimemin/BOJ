#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring> //memset
using namespace std;

const int MAX = 200000 + 200;

int F;
int parent[MAX], setSize[MAX];

//��Ʈ ã�� �Լ�
int findParent(int node)
{
	//���� ��尡 ������ ��Ʈ���
	//�ڽ��� ���� ������ ã�����Ƿ� node ��ȯ
	if (node == parent[node])
		return node;

	//���� ��尡 ������ ��Ʈ�� �ƴ϶��
	//����� ��Ʈ�� ���� ��� ȣ���ϸ鼭 parent[node] ������Ʈ
	return parent[node] = findParent(parent[node]);
}

//������ ��ġ�� �Լ�
void merge(int node1, int node2)
{
	node1 = findParent(node1); //node1�� ���� ������ ã��
	node2 = findParent(node2); //node2�� ���� ������ ã��
	
	//���� ������ �ƴ� ��쿡�� ��ģ��
	if (node1 != node2)
	{
		//ũ�Ⱑ �� ū �������� ���� ������ ��
		if (setSize[node1] < setSize[node2])
		{
			swap(node1, node2);
		}

		parent[node2] = node1; //node2 ������ node1�� ������
		setSize[node1] += setSize[node2]; //node1�� ���� ũ�Ⱑ Ŀ��
		setSize[node2] = 0; //node2�� node1�� ����ǹǷ�
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++)
	{
		cin >> F;

		//�ʱ�ȭ
		for (int i = 0; i < MAX; i++)
		{
			parent[i] = i;
			setSize[i] = 1;
		}

		//map�� ���� ��� �ľ�
		map<string, int> name;
		int idx = 1;

		for (int i = 0; i < F; i++)
		{
			string temp1, temp2;
			cin >> temp1 >> temp2;

			//���� ���� �̸��̶�� �ε��� �ο�
			if (name.count(temp1) == 0)
			{
				name[temp1] = idx++;
			}

			if (name.count(temp2) == 0)
			{
				name[temp2] = idx++;
			}

			//��Ʈ�� ã��
			int temp1Parent = findParent(name[temp1]);
			int temp2Parent = findParent(name[temp2]);

			//���� ���� ���� �ִٸ�
			if (temp1Parent == temp2Parent)
			{
				cout << max(setSize[temp1Parent], setSize[temp2Parent]) << "\n";
			}
			//�ٸ� �����̶�� ��ģ ��
			else
			{
				merge(temp1Parent, temp2Parent);
				cout << max(setSize[temp1Parent], setSize[temp2Parent]) << "\n";
			}
		}
	}

	return 0;
}