#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> adj[102];
int vis[102];

int bfs(vector<int> adj[])
{
    int ans = 0;
    fill(vis, vis + 102, 0);
    
    queue<int> q;    
    q.push(1);
    vis[1] = 1;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int nxt : adj[cur])
        {
            if(!vis[nxt])
            {
                q.push(nxt);
                vis[nxt] = 1;
                ans++;
            }
        }
    }
    return ans;
}

int solution(int n, vector<vector<int>> wires) 
{
    int answer = INT_MAX;
    int total = wires.size();
    int idx = 0;
    
    while(idx < wires.size())
    {        
        for(int i = 0; i < 100; ++i)
            adj[i].clear();
        for(int i = 0; i < wires.size(); ++i)
        {
            if(i == idx)
                continue;
            adj[wires[i][0]].push_back(wires[i][1]);
            adj[wires[i][1]].push_back(wires[i][0]);
        }   
        
        int temp1 = bfs(adj);
        int temp2 = total - temp1 - 1;
        
        answer = min(answer, abs(temp1 - temp2));
        //cout << temp1 << " " << temp2 <<"\n";
                
        idx++;
    }
    
    
    
    
    return answer;
}