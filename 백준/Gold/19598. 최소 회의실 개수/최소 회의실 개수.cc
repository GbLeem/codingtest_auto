#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>>pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int st, en;
		cin >> st >> en;
		vec.push_back({ st,en });		
	}

	//시작 시간 정렬
	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; ++i)
	{
		int st = vec[i].first;
		int en = vec[i].second;

		//사용 가능?
		if (!pq.empty() && pq.top() <= st)
		{
			pq.pop();
		}

		pq.push(en);
	}

	cout << pq.size();
}