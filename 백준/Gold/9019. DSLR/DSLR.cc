#include <iostream>
#include <queue>
#include <string>
using namespace std;

int t;
int vis[10002];

string bfs(int A, int B)
{
	queue<pair<string, int>> q;
	q.push({ "", A });

	while (!q.empty())
	{
		int cur = q.front().second;
		string order = q.front().first;
		q.pop();

		if (cur == B)
		{
			return order;
		}
			
		int nxt = (cur * 2) % 10000;
		if (!vis[nxt])
		{
			q.push({ order + "D", nxt });
			vis[nxt] = 1;
		}			
			
		nxt = cur - 1;
		if (nxt == -1)
			nxt = 9999;

		if (!vis[nxt])
		{
			q.push({ order + "S", nxt });
			vis[nxt] = 1;
		}
			
		nxt = (cur % 1000) * 10 + cur / 1000;

		if (!vis[nxt])
		{
			q.push({ order + "L", nxt });
			vis[nxt] = 1;
		}
			
		//1234
		nxt = (cur / 10) + (cur % 10) * 1000;
		if (!vis[nxt])
		{
			q.push({ order + "R", nxt });
			vis[nxt] = 1;
		}		
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		int A, B;
		cin >> A >> B;

		//D : x2
		//S : -1
		//L : L회전
		//R : R회전
		
		//2d bfs
		
		fill(vis, vis + 10002, 0);
		cout << bfs(A, B) << "\n";
	}
}

