#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

queue<int> q;
stack<int> st;

int solution(vector<int> order)
{
    int answer = 0;
    int curIdx = 0;

    //컨테1 1부터 온다.
    //컨테2 맨앞에만 꺼낼 수 잇음(마지막에 넣은 것)

    // 4 3 1 2 5    
    //맨 앞에서부터 넣다가 못넣으면 끝

    for (int i = 1; i <= order.size(); ++i)
    {
        q.push(i); // 1 2 3 4 5]        
    }

    while (1)
    {
        if (q.empty() && st.empty())
            break;
        if(q.empty() && st.top() != order[curIdx])
            break;

        if (!q.empty() && q.front() == order[curIdx])
        {
            q.pop();
            answer++;
            curIdx++;
        }
        else
        {
            if (!st.empty() && st.top() == order[curIdx])
            {
                st.pop();
                answer++;
                curIdx++;
            }
            else
            {
                st.push(q.front());
                q.pop();
            }
        }
    }

    return answer;
}