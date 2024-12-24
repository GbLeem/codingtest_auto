#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) 
{
    string answer = "";
        
    bool start = false;
    
    //다 대문자로 만들기
    for(int i = 0; i < s.size(); ++i)
    {
        if('a' <= s[i] && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }
   
    int idx = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ' ')
            continue;
        if(i == 0 || s[i - 1] == ' ')
            idx = 0;
        
        //홀수일 때
        if(idx % 2 != 0)
            s[i] += 32;
        idx++;        
    }
    answer = s;
    
    return answer;
}