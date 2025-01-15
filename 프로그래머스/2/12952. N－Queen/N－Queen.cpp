#include <string>
#include <vector>
using namespace std;

int answer = 0;
int N;
int col[14];

bool Check(int cur)
{
    for (int i = 0; i < cur; ++i)
    {
        //열 체크 || 대각선 체크
        if (col[cur] == col[i] || abs(cur - i) == abs(col[cur] - col[i]))
            return false;
    }
    return true;
}

void Choose(int cur)
{
    if (cur == N)
    {
        answer++;
        return;
    }

    //cur 은 행
    //i는 열
    for (int i = 0; i < N; ++i)
    {
        col[cur] = i; //cur행 i열에 퀸 두기

        if (Check(cur))
        {
            Choose(cur + 1);
        }
    }
}

int solution(int n)
{
    N = n;
    Choose(0);

    return answer;
}