#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
// 0 1 2 3 4 5
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	
	vector<long long> nums;
	queue<long long> q;

	for (int i = 0; i <= 9; ++i)
	{
		q.push(i);
		nums.push_back(i);
	}
	while (!q.empty())
	{
		long long cur = q.front();
		q.pop();

		int last_num = cur % 10;

		for (int i = 0; i < last_num; ++i)
		{
			long long nxt_num = cur * 10 + i;
			q.push(nxt_num);
			nums.push_back(nxt_num);
		}
	}
	sort(nums.begin(), nums.end());

	if (n > nums.size())
	{
		cout << -1;
		return 0;
	}
	else
		cout << nums[n - 1];
}