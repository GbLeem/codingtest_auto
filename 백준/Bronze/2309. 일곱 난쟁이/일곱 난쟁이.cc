#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int sum = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; ++i)
	{
		int num;
		cin >> num;
		vec.push_back(num);
		sum += num;
	}

	sort(vec.begin(), vec.end());
	
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		for (int j = i + 1; j < vec.size(); ++j)
		{
			int temp = vec[i] + vec[j];
			if (sum - temp == 100)
			{
				for (const auto& vi : vec)
				{
					if (vi != vec[i] && vi != vec[j])
						cout << vi << "\n";
				}
				return 0;
			}
		}
	}
}