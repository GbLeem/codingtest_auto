#include <string>
#include <vector>
#include <queue>
using namespace std;

int board[100'000'002];

int solution(int storey)
{
    fill(board, board + 100'000'002, -1);
    board[storey] = 0;

    queue<int> q;
    q.push(storey);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int temp = cur; //10
        int size = 0;
        int mod = cur % 10; //0             
            
        int small = - mod;     //16 -6
        int big = 10 - mod; //16 + 4

        for (int nxt : {small, big})
        {
            int realNxt = cur + nxt;
            if (realNxt == cur*10)
                continue;
            realNxt /= 10;
            if (realNxt < 0 || realNxt > 100'000'000)
                continue;
            
            if (board[realNxt] != -1)
                board[realNxt] = min(board[cur] + abs(nxt), board[realNxt]);
            else
                board[realNxt] = board[cur] + abs(nxt);
            if(realNxt != 0)
                q.push(realNxt);
        }
    }

    return board[0];
}