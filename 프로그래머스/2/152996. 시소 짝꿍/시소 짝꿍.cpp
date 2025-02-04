#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, int> um;

long long solution(vector<int> weights)
{
    long long answer = 0;    

    for (int i = 0; i < weights.size(); ++i)    
        um[weights[i]]++;        
    
    for(auto& [w, c] : um)
    {
        if(c > 1)
            answer += (1LL *  c * (c - 1)) / 2;
    }
    
    for(auto& [w, c] : um)
    {
        if(w % 2 == 0 && um.count(w*3/2))
            answer += 1LL * c * um[w * 3 / 2];
        if(um.count(w*2))
            answer += 1LL * c * um[w * 2];
        if(w % 3 == 0 && um.count(w * 4 / 3))
            answer += 1LL * c * um[w * 4 / 3];
    }
   
    return answer;
}