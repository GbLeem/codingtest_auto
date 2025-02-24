#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, string> um;
unordered_map<string, int> um_value;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) 
{
    vector<int> answer;
    for(int i = 0; i < enroll.size(); ++i)
    {
        um[enroll[i]] = referral[i];
    }
    
    for(int i = 0; i < seller.size(); ++i)
    {
        string strKey = seller[i];
        int intValue = amount[i] * 100;
        
        while(strKey != "-")
        {   
            if(intValue * 0.1 < 1)
            {
                //cout << strKey <<" "<<intValue<<"\n";
                um_value[strKey] += intValue;
                break;
            }                        
            else
            {
                um_value[strKey] += (intValue - (int)(intValue * 0.1));
                strKey = um[strKey];
                intValue *= 0.1;        
            }                            
        }
    }
    for(int i = 0; i < enroll.size(); ++i)
    {
        if(um_value[enroll[i]])
            answer.push_back(um_value[enroll[i]]);
        else
            answer.push_back(0);
    }
    return answer;
}