#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int k;
vector<int> adj[20'002];
int vis[20'002];

bool bfs(int start)
{
	int color = 1;
	queue<int> q; 
	q.push(start);
	vis[start] = color;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		
		for (int nxt : adj[cur])
		{
			//인접 한 노드 색 겹침
			if (vis[nxt] != 0 && vis[nxt] == vis[cur])
				return false;
			//방문 안한 경우
			if (vis[nxt] == 0)
			{
				q.push(nxt);
				vis[nxt] = -vis[cur];
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;

	while (k--)
	{	
		int v, e;
		cin >> v >> e;

		for (int i = 1; i <= v; ++i)
			adj[i].clear();

		fill(vis + 1, vis + v + 1, 0);

		for (int i = 0; i < e; ++i)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		bool flag = true;
		for (int i = 1; i <= v; ++i)
		{
			if (vis[i] == 0)
			{
				//이분 그래프 아님
				if (!bfs(i))
				{
					flag = false;
					cout << "NO\n";
					break;
				}
			}
		}
		if(flag)
			cout << "YES\n";
	}
}