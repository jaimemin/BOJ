#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring> //memset
using namespace std;

const int MAX = 200000 + 200;

int F;
int parent[MAX], setSize[MAX];

//루트 찾는 함수
int findParent(int node)
{
	//현재 노드가 집합의 루트라면
	//자신이 속한 집합을 찾았으므로 node 반환
	if (node == parent[node])
		return node;

	//현재 노드가 집합의 루트가 아니라면
	//노드의 루트에 대해 재귀 호출하면서 parent[node] 업데이트
	return parent[node] = findParent(parent[node]);
}

//집합을 합치는 함수
void merge(int node1, int node2)
{
	node1 = findParent(node1); //node1이 속한 집합을 찾음
	node2 = findParent(node2); //node2가 속한 집합을 찾음
	
	//같은 집합이 아닐 경우에만 합친다
	if (node1 != node2)
	{
		//크기가 더 큰 집합으로 작은 집합이 들어감
		if (setSize[node1] < setSize[node2])
		{
			swap(node1, node2);
		}

		parent[node2] = node1; //node2 집합이 node1에 합쳐짐
		setSize[node1] += setSize[node2]; //node1의 집합 크기가 커짐
		setSize[node2] = 0; //node2가 node1에 흡수되므로
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

		//초기화
		for (int i = 0; i < MAX; i++)
		{
			parent[i] = i;
			setSize[i] = 1;
		}

		//map을 통해 사람 파악
		map<string, int> name;
		int idx = 1;

		for (int i = 0; i < F; i++)
		{
			string temp1, temp2;
			cin >> temp1 >> temp2;

			//새로 나온 이름이라면 인덱스 부여
			if (name.count(temp1) == 0)
			{
				name[temp1] = idx++;
			}

			if (name.count(temp2) == 0)
			{
				name[temp2] = idx++;
			}

			//루트를 찾음
			int temp1Parent = findParent(name[temp1]);
			int temp2Parent = findParent(name[temp2]);

			//같은 집합 내에 있다면
			if (temp1Parent == temp2Parent)
			{
				cout << max(setSize[temp1Parent], setSize[temp2Parent]) << "\n";
			}
			//다른 집합이라면 합친 뒤
			else
			{
				merge(temp1Parent, temp2Parent);
				cout << max(setSize[temp1Parent], setSize[temp2Parent]) << "\n";
			}
		}
	}

	return 0;
}