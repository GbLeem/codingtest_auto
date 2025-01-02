#include <string>
#include <vector>
#include <queue>
using namespace std;

int board[100'000'002];
queue<int> q;

int solution(int storey)
{
    //초기화
    fill(board, board + 100'000'002, -1);
    
    //시작값 대입
    board[storey] = 0;
    q.push(storey);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int mod = cur % 10; //1의 자릿수 구하기 

        int small = -mod;   //내려가기
        int big = 10 - mod; //올라가기

        for (int nxt : {small, big})
        {
            //맨 처음으로 나머지 처리를 한 뒤에는 나머지가 계속 0이되기 때문에
            //10으로 나눈 값을 넣어주는 식으로 처리하였고,
            //이전의 값과 비교가 필요해서 realNxt를 구해주는 방식으로 구현하였다.
            int realNxt = cur + nxt; 
            if (realNxt == cur * 10)
                continue;
            realNxt /= 10;

            //바운더리 체크
            if (realNxt < 0 || realNxt > 100'000'000)
                continue;

            //돌의 갯수 계산
            if (board[realNxt] != -1)
                board[realNxt] = min(board[cur] + abs(nxt), board[realNxt]);
            else
                board[realNxt] = board[cur] + abs(nxt);

            //도착한 경우
            if (realNxt != 0)
                q.push(realNxt);
        }
    }

    return board[0];
}