#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<string, int> um;
queue<string> q;

int solution(int cacheSize, vector<string> cities) 
{
    int answer = 0;
    if (cacheSize == 0)
    {
        answer += cities.size()*5;
        return answer;
    }
    for(int i = 0; i < cities.size(); ++i)
    {
        for(int j = 0; j < cities[i].size(); ++j)
        {
            if('a' <= cities[i][j] && cities[i][j] <= 'z')
                cities[i][j] -= 32;
        }
    }
    
    for(int i = 0; i < cities.size(); ++i)
    {
        //cache hit
        bool cachehit = false;
        
        if(um[cities[i]] > 0)
        {
            answer += 1;
            cachehit = true;
        }
        //cache miss
        else
        {
            answer += 5;
            cachehit = false;
        }
                
        if(cachehit)
        {
            queue<string> temp;
            string tempValue = "";

            while(!q.empty())
            {
                //같으면
                if(q.front() == cities[i])
                {
                    tempValue = cities[i];
                    q.pop();
                }
                else
                {
                    temp.push(q.front());
                    q.pop();
                }                
            }           
            temp.push(tempValue);
            q = temp;
        }
        
        //캐시 꽉참
        if(!cachehit && q.size() == cacheSize)
        {                        
            string frontValue = q.front();
            q.pop();
            q.push(cities[i]);
            um[frontValue]--;
            um[cities[i]]++;
        }
        //캐시 비어있을 때
        else if(!cachehit && q.size() < cacheSize)
        {
            q.push(cities[i]);
            um[cities[i]]++;
        }                
    }
    
    return answer;
}