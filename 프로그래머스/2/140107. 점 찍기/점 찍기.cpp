#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(int k, int d) 
{
    long long answer = 0;

    for (int x = 0; x <= d; x += k) 
    {
        // y 최대값 계산 (제곱근 사용 없이 효율적 처리)
        long long max_y_squared = (long long)d * d - (long long)x * x;
        long long max_y = sqrt(max_y_squared);

        // y 좌표는 k 간격으로 증가
        answer += (max_y / k) + 1;
    }

    return answer;
}
