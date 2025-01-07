#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pqA;
priority_queue<int, vector<int>, greater<int>> pqB;

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}

int solution(vector<int> arrayA, vector<int> arrayB) 
{
    int answer = 0;
    //a1 a2의 최대공약수로 
    //b1 b2 안나눠떨어지면 ok
    
    for(int i = 0; i < arrayA.size(); ++i)
    {
        pqA.push(arrayA[i]);
        pqB.push(arrayB[i]);
    }
    while(pqA.size() > 1)
    {
        int a = pqA.top();
        pqA.pop();
        int b = pqA.top();
        pqA.pop();
        int g = gcd(a, b);
        pqA.push(g);
    }
    
    //cout << pqA.top() <<"\n";    
    
    bool flag = true;
    for(auto b : arrayB)
    {
        //나눠 떨어지면 안됌
        if(b % pqA.top() == 0)
            flag = false;            
    }
    if(flag)
        answer = pqA.top();
    
    //반대도 해서 큰 수 정답
    while(pqB.size() > 1)
    {
        int a = pqB.top();
        pqB.pop();
        int b = pqB.top();
        pqB.pop();
        int g = gcd(a, b);
        pqB.push(g);
    }
    //cout << pqB.top();
    bool flag2 = true;
    for(auto a : arrayA)
    {
        if(a % pqB.top() == 0)
            flag2 = false;            
    }
    if(flag2)
        answer = max(answer, pqB.top());
    
    
    return answer;
}