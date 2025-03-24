#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

priority_queue<int> pq; //무적권 사용할 리스트

int solution(int n, int k, vector<int> enemy)
{
    int answer = 0;

    for (int i = 0; i < enemy.size(); ++i)
    {
        if (n >= enemy[i])
        {
            n -= enemy[i];
            pq.push(enemy[i]);
            answer++;
        }
        //무적권 써야함
        else
        {
            //쓸 수 있는 경우
            if (k > 0)
            {
                if (!pq.empty() && pq.top() > enemy[i])
                {
                    n += pq.top();
                    pq.pop();
                    pq.push(enemy[i]);
                    n -= enemy[i];
                }                
                k--;
                answer++;                
            }
            else
                return answer;
        }                   
    }

    return answer;
}