#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[9];
vector<int> ans;
vector<int> res;
int sum = 0;

void Choose(int cur)
{
	if (cur == 2)
	{
		int tempSum = sum;
		tempSum -= arr[ans[0]];
		tempSum -= arr[ans[1]];

		if (tempSum == 100)
		{
			res.clear();
			for (int i = 0; i < 9; ++i)
			{
				if (i != ans[0] && i != ans[1])
					res.push_back(arr[i]);
			}
		}
		return;
	}
	for (int i = 0; i < 9; ++i)
	{
		ans.push_back(i);
		Choose(cur + 1);
		ans.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	Choose(0);

	sort(res.begin(), res.end());
	for (const auto& r : res)
	{
		cout << r << "\n";
	}
}