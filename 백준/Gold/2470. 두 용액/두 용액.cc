#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<long long> vec;
vector<int> ans(2);
long long answer = LLONG_MAX;

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
	sort(vec.begin(), vec.end());

	//0에 가장 가까운 값 만들기
	//내 값이 -10이면 (0 - 10) 이랑 가장 가까운수를 찾아야 함
	//찾고자 하는 값보다 크거나 같은 값 -> 이거보다 하나 작은 값
	//찾고자 하는 값보다 큰 값

	for (int i = 0; i < vec.size(); ++i)
	{
		int temp = 0 - vec[i];
		
		int idxsmall = -1;
		int idxfind = -1;
		int idxbig = -1;
		
		if (lower_bound(vec.begin(), vec.end(), temp) != vec.end())
		{
			idxfind = lower_bound(vec.begin(), vec.end(), temp) - vec.begin();
			if (idxfind == i)
				continue;
			if (answer > abs(vec[i] + vec[idxfind]))
			{
				ans[0] = vec[i];
				ans[1] = vec[idxfind];
				answer = abs(vec[i] + vec[idxfind]);
			}

			//하나 작은 값
			if (idxfind - 1 >= 0 && idxfind - 1 != i)
			{
				idxsmall = idxfind - 1;
				if (idxsmall == i)
					continue;
				if (answer > abs(vec[i] + vec[idxsmall]))
				{
					ans[0] = vec[i];
					ans[1] = vec[idxsmall];
					answer = abs(vec[i] + vec[idxsmall]);
				}
			}
		}
		else
		{
			idxbig = vec.size() - 1;
			if (idxbig == i)
				continue;
			if (answer > abs(vec[i] + vec[idxbig]))
			{
				ans[0] = vec[i];
				ans[1] = vec[idxbig];
				answer = abs(vec[i] + vec[idxbig]);
			}
		}
		if (upper_bound(vec.begin(), vec.end(), temp) != vec.end())
		{
			idxbig = upper_bound(vec.begin(), vec.end(), temp) - vec.begin();
			if (idxbig == i)
				continue;
			if (answer > abs(vec[i] + vec[idxbig]))
			{
				ans[0] = vec[i];
				ans[1] = vec[idxbig];
				answer = abs(vec[i] + vec[idxbig]);
			}
		}				
	}
	sort(ans.begin(), ans.end());
	cout << ans[0] << " " << ans[1];
}