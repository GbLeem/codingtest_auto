#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist[55];
int value[55][55];
vector<int> adj[55];

void bfs()
{
    fill(dist, dist + 55, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(auto nxt : adj[cur])
        {
            if(dist[nxt] == -1)
            {
                q.push(nxt);
                dist[nxt] = dist[cur] + value[cur][nxt];                
            }
            if(dist[nxt] > dist[cur] + value[cur][nxt])
            {
                q.push(nxt);
                dist[nxt] = dist[cur] + value[cur][nxt];                
            }            
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) 
{
    int answer = 0;
    for(int i = 0; i < road.size(); ++i)
    {
        adj[road[i][0]].push_back(road[i][1]);        
        if(value[road[i][0]][road[i][1]] != 0)
            value[road[i][0]][road[i][1]] = min(value[road[i][0]][road[i][1]], road[i][2]);
        else
            value[road[i][0]][road[i][1]] = road[i][2];
        adj[road[i][1]].push_back(road[i][0]);
        if(value[road[i][1]][road[i][0]] != 0)
            value[road[i][1]][road[i][0]] = min(value[road[i][1]][road[i][0]], road[i][2]);
        else
            value[road[i][1]][road[i][0]] = road[i][2];
    }
    
    bfs();
    
    for(int i = 1; i <= N; ++i)
    {
        if(dist[i] <= K)
        {
            answer++;
        }
    }

    return answer;
}