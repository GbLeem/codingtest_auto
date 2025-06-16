//덮어써질 우려가 있음,,,
//최단 경로가 아니라 뭔가 다 해보고 찾는 경우 dfs (백트래킹) 기법을 사용할껏
//추가적으로 배열의 크기도 22x22로 매우 작으니까 의심할만하다.

#include <iostream>
#include <string>
#include <stack>
#include <climits>
using namespace std;

int R, C;
string arr[22];
bool vis[28];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int answer = -1;

void dfs(int x, int y, int cnt)
{
	answer = max(answer, cnt);

	for (int dir = 0; dir < 4; ++dir)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			continue;

		if (!vis[arr[nx][ny] - 'A'])
		{
			vis[arr[nx][ny] - 'A'] = 1;
			dfs(nx, ny, cnt + 1);
			vis[arr[nx][ny]- 'A'] = 0;
		}
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; ++i)
	{
		cin >> arr[i];
	}

	vis[arr[0][0] - 'A'] = 1;

	dfs(0, 0, 1);

	cout << answer;	
}