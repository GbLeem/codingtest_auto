#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int K;
vector<int> STONES;

bool Check(int M)
{
    int zeroValue = 0;
    
    for(int s : STONES)
    {
        if(s - M < 0)
            zeroValue++;
        else
            zeroValue = 0;
        
        if(zeroValue >= K)
            return false;
    }
    return true;
}
int solution(vector<int> stones, int k) 
{
    int answer = 0;
    STONES = stones;
    K = k;
    
    int left = 1;
    int right = *max_element(STONES.begin(), STONES.end());
    
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if(Check(mid))
        {
            answer = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }    
    
    return answer;
}