#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct
{
	int r, g, b;
} RGB;

typedef struct
{
	int i, j;
} Idx;

bool cmp(Idx a, Idx b)
{
	if (a.i < b.i)
	{
		return true;
	}

	if (a.i == b.i)
	{
		return a.j < b.j;
	}

	return false;
}

double getContrast(RGB rgb, RGB rgb2)
{
	return sqrt((rgb.r - rgb2.r) * (rgb.r - rgb2.r) 
		+ (rgb.g - rgb2.g) * (rgb.g - rgb2.g) 
		+ (rgb.b - rgb2.b) * (rgb.b - rgb2.b));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int K;
	cin >> K;

	for (int k = 1; k <= K; k++)
	{
		int n;
		cin >> n;

		vector<RGB> rgbs(n);

		for (int i = 0; i < n; i++)
		{
			RGB rgb;
			cin >> rgb.r >> rgb.g >> rgb.b;

			rgbs[i] = rgb;
		}

		double temp = 0.0;
		vector<Idx> results;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (temp < getContrast(rgbs[i], rgbs[j]))
				{
					results.clear();
					results.push_back({ i + 1, j + 1 });

					temp = getContrast(rgbs[i], rgbs[j]);
				}
				else if (temp == getContrast(rgbs[i], rgbs[j]))
				{
					results.push_back({ i + 1, j + 1 });
				}
			}
		}

		sort(results.begin(), results.end(), cmp);

		cout << "Data Set " << k << ":\n";

		for (Idx result : results)
		{
			cout << result.i << " " << result.j << "\n";
		}
	}

	return 0;
}