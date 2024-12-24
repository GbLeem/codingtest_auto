#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> solution(int n, long long left, long long right) 
{
    vector<int> answer;
    
    for(long long i = left; i <= right ; ++i)
    {
        int x = i / n + 1;
        int y = i % n + 1;
            
        int maxValue = max(x, y);
        answer.push_back(maxValue);      
    }        
    
    return answer;
}