//가장 비싼 보석부터 넣을 수 있는 가장 작은 가방 쓰기

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, c;
vector<pair<int, int>> jew;
multiset<int> bag;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k; // 보석 갯수, 가방 갯수
	
	for (int i = 0; i < n; ++i)
	{
		int m, v;
		cin >> m >> v;
		jew.push_back({ v, m }); //가격, 무게
	}
	sort(jew.begin(), jew.end()); //가격 오름차순 정렬 (23 5 -> 65 1 -> 99 2)

	for (int i = 0; i < k; ++i)
	{
		cin >> c; //각 가방의 최대 무게
		bag.insert(c);
	}

	long long ans = 0;

	for (int i = n - 1; i >= 0; --i)
	{
		int m, v;
		m = jew[i].second; //무게 2 10
		v = jew[i].first; //가격
		auto it = bag.lower_bound(m); // m이 들어가도 오름차순이 깨지지 않는 가장 왼쪽의 원소

		if (it == bag.end()) 
			continue;
		ans += v;
		bag.erase(it);
	}
	cout << ans;
}