#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<int> solution(vector<int> sequence, int k) 
{
    vector<int> answer;
        
    int size = sequence.size();
    int en = 0;
    int sum = 0;
    int length = INT_MAX;
    
    for(int st = 0; st < size; ++st)
    {        
        while(st <= en && en <= size)
        {                                   
            if(sum == k)
            {
                if(length > en - st + 1)
                {
                    length = en - st + 1;
                    answer.clear();
                    answer.push_back(st);
                    answer.push_back(en-1);
                }
                break;
            }
            if(sum > k)
                break;
            sum += sequence[en];
            en++;
        }        
        sum -= sequence[st];
    }
    
    
    return answer;
}