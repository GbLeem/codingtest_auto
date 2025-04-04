#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int m;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<pair<int, int>> ans;
int isused[15];
int answer = INT_MAX;

void Check(vector<pair<int, int>>& ans)
{
	int temp = 0;
	for (int i = 0; i < home.size(); ++i)
	{
		int minDist = INT_MAX;
		for (const auto a : ans)
		{	
			minDist = min(abs(home[i].first - a.first) + abs(home[i].second - a.second), minDist);
		}
		temp += minDist;
	}
	answer = min(answer, temp);
}

void Choose(int cur, int start)
{
	if (cur == m)
	{
		Check(ans);
		return;
	}
	for (int i = start; i < chicken.size(); ++i)
	{
		if (!isused[i])
		{
			ans.push_back(chicken[i]);
			isused[i] = 1;
			Choose(cur + 1, i + 1);
			ans.pop_back();
			isused[i] = 0;
			
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int num;
			cin >> num;

			if (num == 2)
				chicken.push_back({ i,j });
			if (num == 1)
				home.push_back({ i,j });
		}
	}

	for (int i = 0; i < m; ++i)
	{
		Choose(i, 0); //0->3 / 1->2 / 2->1
	}

	cout << answer;
}