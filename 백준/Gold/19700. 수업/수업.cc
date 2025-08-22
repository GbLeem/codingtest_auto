#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n;
pair<int, int>arr[500'002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].first >> arr[i].second; //키, 등수		
	}

	sort(arr, arr + n, greater<pair<int, int>>());
	multiset<int> ms;

	for (int i = 0; i < n; ++i)
	{
		//x-1명 이하인 팀 중에서 가장 많은 팀원인 곳 고르기
		auto it = ms.lower_bound(-arr[i].second + 1);
		if (it == ms.end())
			ms.insert(-1);
		else
		{
			ms.insert(*it - 1);
			ms.erase(it);
		}
	}
	cout << ms.size();
}