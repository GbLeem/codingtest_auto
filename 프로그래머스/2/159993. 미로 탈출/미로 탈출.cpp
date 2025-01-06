#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int answer = 0;
char board[102][102]; //row col
int vis[102][102];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int row = 0;
int col = 0;

int bfs(pair<int, int> st, pair<int, int> en)
{
    for (int i = 0; i < row; ++i)
        fill(vis[i], vis[i] + col, -1);

    queue<pair<int, int>> q;
    q.push({ st.first, st.second });
    vis[st.first][st.second] = 0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= row || ny < 0 || ny >= col)
                continue;
            if (board[nx][ny] == 'X' || vis[nx][ny] != -1) //벽이거나, 이미 방문한 경우
                continue;
            if (nx == en.first && ny == en.second)
            {
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
                return vis[nx][ny];
            }

            q.push({ nx, ny });
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }
    return -1;
}

int solution(vector<string> maps)
{
    int answer = 0;
    pair<int, int> s;
    pair<int, int> e;
    pair<int, int> l;

    row = maps.size();
    col = maps[0].size();

    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            if (maps[i][j] == 'S')
                s = { i,j };
            else if (maps[i][j] == 'E')
                e = { i,j };
            else if (maps[i][j] == 'L')
                l = { i, j };
            else if (maps[i][j] == 'O')
                board[i][j] = 'O';
            else if (maps[i][j] == 'X')
                board[i][j] = 'X';
        }
    }

    if (bfs(s, l) == -1)
        return -1;
    answer += bfs(s, l);        
    if (bfs(l, e) == -1)
        return -1;
    answer += bfs(l, e);

    return answer;
}