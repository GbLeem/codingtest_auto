#include <string>
#include <vector>
#include <iostream>
using namespace std;

int board[1002][1002];
int dx[3] = { 1, 0, -1 };
int dy[3] = { 0, 1, -1 };

vector<int> Print(int n)
{
    vector<int> ans;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] != 0)
                ans.push_back(board[i][j]);
        }
    }
    return ans;
}

vector<int> solution(int n)
{
    vector<int> answer;

    int total = 0;
    for (int i = 1; i <= n; ++i)
        total += i;

    pair<int, int> cur = { 0, 0 };
    int dir = 0;
    board[0][0] = 1;

    for (int i = 1; i < total; ++i)
    {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];

        if (board[nx][ny] != 0)
        {
            dir = (dir + 1) % 3;
            nx = cur.first + dx[dir];
            ny = cur.second + dy[dir];
        }
        else if (nx >= n || ny >= n)
        {
            dir = (dir + 1) % 3;
            nx = cur.first + dx[dir];
            ny = cur.second + dy[dir];
        }

        board[nx][ny] = board[cur.first][cur.second] + 1;
        cur = { nx, ny };
    }

    answer = Print(n);

    return answer;
}