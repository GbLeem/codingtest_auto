#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> vec;
int answer = 0;

void func(int i)
{
	for (int j = 0; j < n; ++j)
	{
		if (j == i)
			continue;
		int temp = vec[i] - vec[j];

		int idx = lower_bound(vec.begin(), vec.end(), temp) - vec.begin();

		while (idx < n && vec[idx] == temp)
		{
			if (idx != j && idx != i)
			{
				answer++;
				return;
			}
			idx++;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end()); //-5 0 5

	for (int i = 0; i < n; ++i)
	{
		/*for (int j = 0; j < n; ++j)
		{
			if (j == i)
				continue;
			int temp = vec[i] - vec[j];
			
			int idx = lower_bound(vec.begin(), vec.end(), temp) - vec.begin();			

			if (idx != j && idx != i && idx < vec.size() && vec[idx] == temp)
			{
				answer++;
				break;
			}
		}*/
		func(i);
	}

	cout << answer;
}