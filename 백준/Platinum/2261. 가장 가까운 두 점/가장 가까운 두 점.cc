#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<pair<long long, long long>> board;

bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

long long Dist(pair<long long, long long> a, pair<long long, long long> b)
{
	long long dx = a.first - b.first;
	long long dy = a.second - b.second;
	return dx * dx + dy * dy;	
}

long long Check(int st, int en)
{
	if (en - st + 1 <= 3)
	{
		long long temp = LLONG_MAX;
		for (int i = st; i <= en; ++i)
		{
			for (int j = i + 1; j <= en; ++j)
			{
				temp = min(temp, Dist(board[i], board[j]));
			}
		}
		return temp;
	}

	int mid = (st + en) / 2;
	long long L = Check(st, mid);
	long long R = Check(mid + 1, en);
	long long M = min(L, R);

	vector<pair<long long, long long>> vec;

	long long sep = board[mid].first;

	for (int i = st; i <= en; ++i)
	{
		long long dist = board[i].first - sep;
		if (dist * dist < M)
			vec.push_back(board[i]);
	}
	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = i + 1; j < vec.size(); ++j)
		{
			long long dist = vec[j].second - vec[i].second;
			if (dist * dist >= M)
				break;
			M = min(M, Dist(vec[i], vec[j]));
		}
	}

	return M;
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
		board.push_back({ x, y });		
	}

	sort(board.begin(), board.end());

	cout << Check(0, board.size() - 1);
}