#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

string solution(string number, int k) 
{
    string answer = "";
    stack<char> st;
    
    for(int i = 0; i < number.size(); ++i)
    {
        while(!st.empty() && k > 0 && st.top() < number[i])
        {
            st.pop();
            k--;
        }
        st.push(number[i]);      
    }        
    
    while(k > 0 && !st.empty()) 
    {
        st.pop();
        k--;
    }
    
    while(!st.empty())
    {
        answer += st.top();
        st.pop();
    }
    
    reverse(answer.begin(), answer.end());    
    //answer = answer.substr(0, answer.size() - k);
    
    return answer;
}