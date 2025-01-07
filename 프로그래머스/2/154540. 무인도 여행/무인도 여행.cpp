#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[102][102];
int vis[102][102];
queue<pair<int, int>> q;

vector<int> solution(vector<string> maps) 
{
    vector<int> answer;
    int row = maps.size();
    int col = maps[0].size();
    
    for(int i = 0; i < maps.size(); ++i)
    {
        for(int j = 0; j < maps[0].size(); ++j)
        {
            if(vis[i][j] == 0 && maps[i][j] != 'X') // 방문하지 않았고, 바다 아닐때
            {
                //cout << "(" << i <<", " << j <<")\n";
                q.push({i, j});
                vis[i][j] = 1;
                int days = maps[i][j] - 48;
                
                while(!q.empty())
                {
                    auto cur = q.front();
                    q.pop();
                    
                    for(int dir = 0; dir < 4; ++dir)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        
                        if(nx < 0 || nx >= row || ny < 0 || ny >= col)
                            continue;
                        if(vis[nx][ny] != 0 || maps[nx][ny] == 'X') //이미 방문했거나 바다일 때
                            continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                        days += (maps[nx][ny] - 48);
                    }
                }
                answer.push_back(days);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.empty())
        answer.push_back(-1);
    
    return answer;
}