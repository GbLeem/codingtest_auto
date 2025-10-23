#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
int T = 0;
vector<pair<int, int>> vec;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;

		vec.push_back({ x, y });
	}
	
	//중복된 x나 y갯수 중 가장 큰것 지우기를 세번 해서 다 없어지면 ok
	while (1)
	{
		unordered_map<int, int> umX;
		unordered_map<int, int> umY;

		for (const auto& v : vec)
		{
			if (v.first == -1)
				continue;
			umX[v.first]++;
			umY[v.second]++;
		}

		int maxCnt = 0;
		int maxIdx = -1;
		for (const auto& x : umX)
		{
			if (x.second > maxCnt)
			{
				maxCnt = x.second;
				maxIdx = x.first;
			}
		}

		int maxCntY = 0;
		int maxIdxY = -1;

		for (const auto& y : umY)
		{
			if (y.second > maxCntY)
			{
				maxCntY = y.second;
				maxIdxY = y.first;
			}
		}

		if (maxCntY > maxCnt)
		{
			for (int i = 0; i < vec.size(); ++i)
			{
				if (vec[i].second == maxIdxY)
				{
					vec[i].first = -1;
					vec[i].second = -1;
				}
			}
		}
		else
		{
			for (int i = 0; i < vec.size(); ++i)
			{
				if (vec[i].first == maxIdx)
				{
					vec[i].first = -1;
					vec[i].second = -1;
				}
			}
		}
		T++;

		if (T == 3)
			break;
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i].first != -1)
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}