#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, k;
vector<pair<int, int>> gem;
multiset <int> bag;
long long answer = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		int m, v;
		cin >> m >> v;
		gem.push_back({ v, m }); //가격, 무게
	}

	for (int i = 0; i < k; ++i)
	{
		int c;
		cin >> c;
		bag.insert(c);
	}

	sort(gem.begin(), gem.end(), greater<pair<int, int>>());

	for (int i = 0; i < gem.size(); ++i)
	{
		auto it = bag.lower_bound(gem[i].second);
		if (it != bag.end())
		{
			answer += gem[i].first;
			bag.erase(it);
		}
	}

	cout << answer;
}