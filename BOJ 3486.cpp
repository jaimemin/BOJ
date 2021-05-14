#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string getResultWithoutUnnecessaryZeros(string result) 
{ 
	// ���ʷ� 0�� �ƴ� �ε����� ã�´� 
	int firstNonZeroIdx = result.size(); 
	
	for (int i = 0; i < result.size(); i++) 
	{ 
		if (result[i] != '0') 
		{ 
			firstNonZeroIdx = i; 
			
			break; 
		} 
	} // ��� �ڸ��� 0�̶�� 0�� ��ȯ 
	
	if (firstNonZeroIdx == result.size()) 
	{ 
		return "0"; 
	} 
	// ���ʷ� 0�� �ƴ� �ڸ������� ���ڵ��� ��ȯ 
	
	return result.substr(firstNonZeroIdx); 
}


void printReverseSum(string a, string b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string sum = to_string(stoi(a) + stoi(b));
	reverse(sum.begin(), sum.end());

	cout << getResultWithoutUnnecessaryZeros(sum) << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int n = 0; n < N; n++)
	{
		string a, b;
		cin >> a >> b;

		printReverseSum(a, b);
	}

	return 0;
}