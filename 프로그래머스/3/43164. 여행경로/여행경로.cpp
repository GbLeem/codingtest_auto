#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, vector<string>> um;
vector<string> answer;

void DFS(string cur)
{
    while (!um[cur].empty())
    {
        string nxt = um[cur].front();
        um[cur].erase(um[cur].begin());
        DFS(nxt);
    }
    answer.push_back(cur);
}

vector<string> solution(vector<vector<string>> tickets)
{
    for (int i = 0; i < tickets.size(); ++i)
    {
        um[tickets[i][0]].push_back(tickets[i][1]);
    }
    
    for(auto & [key, value] : um)
    {
        sort(value.begin(), value.end());
    }
    DFS("ICN");

    reverse(answer.begin(), answer.end());

    return answer;
}