#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> book_time) 
{
    int answer = 0;
    vector<pair<int,int>> vec;
    
    for(int i = 0; i < book_time.size(); ++i)
    {
        string temp1;
        string temp2;
        
        temp1 += book_time[i][0].substr(0,2);
        temp1 += book_time[i][0].substr(3,2);
        temp2 += book_time[i][1].substr(0,2);
        temp2 += book_time[i][1].substr(3,2);
        
        vec.push_back({stoi(temp1), stoi(temp2)});
    }
    
    sort(vec.begin(), vec.end());//start 기준으로 정렬
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //end, start, 오름차순
    
    for(int i = 0; i < vec.size(); ++i)
    {
        //가장 빨리 끝나는 방 + 10 보다 새로운 방의 시작점이 늦으면 pop
        if(!pq.empty())
        {
            int nextTime = pq.top().first + 10; //1367   
            if(nextTime % 100 >= 60)
            {                                
                nextTime = (nextTime / 100 + 1) * 100 + nextTime % 10;              
            }
             
            if(nextTime <= 2359 && nextTime <= vec[i].first)
                pq.pop();                
        }        
        pq.push({vec[i].second, vec[i].first});
        answer = max(answer, (int)pq.size());
    }
    
    return answer;    
}