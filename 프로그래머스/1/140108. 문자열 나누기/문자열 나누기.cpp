#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = 0;
    
    char temp = s[0];
    int cnt1 = 0;
    int cnt2 = 0;
    int idx = 0;

    while(1)
    {
        if (s.size() == 1)
        {
            answer++;
            break;
        }
        if (cnt1 != cnt2 && s.size() == idx + 1)
        {
            answer++;
            break;
        }
            

        if (temp == s[idx])
            cnt1++;
        else
            cnt2++;

        if (cnt1 == cnt2)
        {
            s = s.substr(idx + 1);
            idx = 0;
            cnt1 = 0;
            cnt2 = 0;
            temp = s[0];
            answer++;
        }
        else
            idx++;
    }
    
    return answer;
}