#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) 
{
    int answer = 0;
    vector<int> ans;
    unordered_map<string, int> um;
    
    for(int i = 0; i < 10; ++i)
    {
        if(i == 0)
        {
            um["zero"] = -1;    
        }
        else
        {
            um[arr[i]] = i;       
        }        
    }
    string temp;    
    
    for(int i = 0; i < s.size(); ++i)
    {
        if(isdigit(s[i]))
        {
            if(!temp.empty())
            {
                ans.push_back(um[temp]);
                temp.clear();                
            }

            ans.push_back(s[i] - '0');
        }
        else
        {
            temp += s[i];
        }
        
        if(!temp.empty() && um[temp])
        {
            ans.push_back(um[temp]);
            temp.clear();
        }    
    }
    
    
    int num = 1;
    for(int i = ans.size() - 1; i >= 0; --i)
    {
        if(ans[i] == -1)
        {
            ans[i] = 0;
        }
        answer += ans[i] * num;
        num *= 10;
    }
    
    return answer;
}