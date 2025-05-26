#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, c;
unordered_map<int, int> cnt; //value count
unordered_map<int, int> idx; //value idx

bool cmp(pair<int, int> a, pair<int, int>b)
{
	//count가 같은 경우
	if (a.second == b.second)
		return idx[a.first] < idx[b.first];
	return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> c;

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		
		cnt[num]++;
		if (idx[num] == 0)
		{
			//인덱스 0방지
			idx[num] = i + 1;
		}
	}
	//복제
	//value, count
	vector<pair<int, int>> vec(cnt.begin(), cnt.end());
	sort(vec.begin(), vec.end(), cmp);

	for (const auto& v : vec)
	{
		for (int i = 0; i < v.second; ++i)
		{
			cout << v.first << " ";
		}
	}
}