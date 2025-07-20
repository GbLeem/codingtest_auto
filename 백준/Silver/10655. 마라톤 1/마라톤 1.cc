#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
vector<pair<int, int>> vec;
int answer = INT_MAX;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;

		vec.push_back({ x, y });
	}
	
	vector<int> dists;
	int totaldist = 0;

	for (int i = 0; i < N - 1; ++i)
	{
		dists.push_back(abs(vec[i].first - vec[i + 1].first) + abs(vec[i].second - vec[i + 1].second));
		totaldist += abs(vec[i].first - vec[i + 1].first) + abs(vec[i].second - vec[i + 1].second);
	}

	for (int i = 1; i < N - 1; ++i)
	{
		int tempdist = totaldist;
		tempdist -= (dists[i] + dists[i - 1]);
		tempdist += (abs(vec[i-1].first - vec[i+1].first) + abs(vec[i - 1].second - vec[i + 1].second));		
		
		answer = min(tempdist, answer);
	}
	cout << answer;
}