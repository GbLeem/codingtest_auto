//아마도 dfs 백트래킹?

//맞음
//중요한건 도착체크 위에서 하는게 맞음 
//백트래킹 느낌을 생각하기 (1987 유사)

#include <iostream>
using namespace std;

int r, c, k;
string arr[6];
int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int vis[6][6];
int answer = 0;

void dfs(int x, int y, int cnt)
{
	//도착체크를 먼저
	if (x == 0 && y == c - 1 && cnt == k)
	{		
		answer++;
		return;				
	}	

	for (int dir = 0; dir < 4; ++dir)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;
		if (vis[nx][ny] == 0 && arr[nx][ny] != 'T')
		{
			vis[nx][ny] = 1;
			dfs(nx, ny, cnt+1);
			vis[nx][ny] = 0;
		}		
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> k;

	for (int i = 0; i < r; ++i)
	{
		cin >> arr[i];
	}
	vis[r - 1][0] = 1;
	dfs(r - 1, 0, 1);
	cout << answer;
}