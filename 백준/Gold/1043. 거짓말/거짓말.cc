#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int t;
int tarr[52];
vector<int> Data[52];
vector<int> adj[52];
int vis[52];
int answer = 0;

void bfs(int cur)
{
	queue<int>q;
	q.push(cur);
	vis[cur] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur])
		{
			if (!vis[nxt])
			{
				vis[nxt] = 1;
				q.push(nxt);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//사람, 파티
	cin >> n >> m;
	//진실
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> tarr[i];
	}
	
	for (int i = 0; i < m; ++i)
	{
		int p;
		cin >> p;
		for (int j = 0; j < p; ++j)
		{
			int num;
			cin >> num;
			Data[i].push_back(num);			
		}
		for (int j = 0; j < Data[i].size() - 1; ++j)
		{
			adj[Data[i][j]].push_back(Data[i][j + 1]);
			adj[Data[i][j + 1]].push_back(Data[i][j]);
		}
	}

	for (const auto& ta : tarr)
	{
		bfs(ta);
	}

	for (int i = 0; i < m; ++i)
	{
		bool fun = true;
		for(int j = 0 ; j < Data[i].size();++j)
		{
			if (vis[Data[i][j]])
			{
				fun = false;
				break;
			}
		}
		if (fun)
			answer++;
	}
	cout << answer;
}