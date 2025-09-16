#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<vector<pair<int, int>>> vec;
int answer = 0;
int board[42][42];

void Rotate(vector<pair<int, int>>& vec, int& r, int& c)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		int nx = vec[i].second;
		int ny = (r - 1) - vec[i].first;

		vec[i].first = nx;
		vec[i].second = ny;
	}
	swap(r, c);
}

bool Check(vector<pair<int,int>> vec)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int flag = true;
			for (const auto& v : vec)
			{
				int nx = i + v.first;
				int ny = j + v.second;

				if (board[nx][ny] == 1)
				{
					flag = false;
					break;
				}
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				{
					flag = false;					
					break;
				}
			}
			if (flag)
			{
				for (const auto& v : vec)
				{
					int nx = i + v.first;
					int ny = j + v.second;
					board[nx][ny] = 1;
				}
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i)
	{
		int r, c;
		cin >> r >> c;

		vector<pair<int, int>> temp;

		for (int x = 0; x < r; ++x)
		{
			for (int y = 0; y < c; ++y)
			{
				int num;
				cin >> num;
				if (num == 1)
					temp.push_back({x, y});
			}
		}
		
		for (int i = 0; i < 4; ++i)
		{
			if (Check(temp))
			{
				answer += temp.size();
				break;
			}
			else
			{
				Rotate(temp, r, c);
			}
		}
	}

	cout << answer;
}