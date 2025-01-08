#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) 
{
    long long answer = 0;
    
    for(int x = 1; x <= r2; ++x)
    {
        long long maxY = (long long)r2 * r2 - (long long)x * x;
        maxY = sqrt(maxY);  
                                            
        answer += (maxY + 1) * 4;          
        //cout << maxY<<"\n";
    }     
    
    
    for(int x = 1; x < r1; ++x)
    {
        bool same = false;
        long long minY = (long long)r1 * r1 - (long long)x * x;                    
        minY = sqrt(minY);
        if((long long)minY*minY + (long long)x * x == (long long)r1*r1)
            same = true; 
        
        if(same)
        {
            //cout << minY <<"\n";
            answer -= (minY) * 4;
        }
            
        else
            answer -= (minY + 1) * 4;        
    }
    
    return answer;
}