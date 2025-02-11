#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<float, int>&a, pair<float, int>&b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;    
    int totalUsers = stages.size();    
    unordered_map<int,int> board;
    vector<pair<float, int>> vec;    
    
    sort(stages.begin(), stages.end()); //1 2 2 2 3 3 4 6
    for(int i = 0; i < stages.size(); ++i)
    {
        board[stages[i]]++;
    }
    
    for(int i = 1; i <= N; ++i)
    {                
        if(totalUsers <= 0)
            vec.push_back({0.f, i});    
        else
        {
            float probability = (float)board[i] / totalUsers;
            totalUsers -= board[i];
            vec.push_back({probability, i});            
        }
        
    }
    
    sort(vec.begin(), vec.end() ,cmp);
    for(const auto& v : vec)
        answer.push_back(v.second);

    return answer;
}