#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

bool isUsed[30];
vector<int> ans;
map<string, int> m;

void Choose(int size, string str, string res)
{
    if(res.size() == size)
    {
        m[res]++;
        //for(auto r : res)
        //    cout << r;
        //cout<<"\n";
    }
        
    for(int i = 0; i < str.size(); ++i)
    {
        Choose(size, str.substr(i + 1), res + str[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> answer;
    
    for(auto& o : orders)    
        sort(o.begin(), o.end());
    
    for(int i = 0; i < course.size(); ++i)
    {
        for(int j = 0; j < orders.size(); ++j)        
            Choose(course[i], orders[j], "");
        
        int maxCnt = -1;
        for(const auto& mi : m)
            maxCnt = max(maxCnt, mi.second);
        
        for(const auto& mi : m)
        {
            if(maxCnt >= 2 && maxCnt == mi.second) //최대인 경우
            {
                answer.push_back(mi.first);
            }
        }
        
        m.clear();
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}