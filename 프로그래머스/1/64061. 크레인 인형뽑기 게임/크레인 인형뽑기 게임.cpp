#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<int> st;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    int colLength = board.size();
    
    for(int i = 0; i < moves.size(); ++i)
    {
        for(int x = 0; x < colLength; ++x)
        {
            if(board[x][moves[i]-1] != 0)
            {
                int cur = board[x][moves[i]-1];
                if(!st.empty() && st.top() == cur)
                {
                    st.pop();
                    answer += 2;
                }                    
                else
                    st.push(board[x][moves[i]-1]);
                
                board[x][moves[i]-1] = 0;   
                break;
            }
        }        
    }
    return answer;
}