#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isprime(long n)
{
    if(n == 1 || n == 0)
        return false;
    for(long i = 2; i*i <= n; ++i)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) 
{
    int answer = 0;
    vector<int> temp;
    vector<long> test;
    
    while(n > k)
    {
        temp.push_back(n % k);
        n /= k;
    }
    temp.push_back(n);
    
    long value = 0;
    long mul = 1;
    
    for(int i = 0; i < temp.size(); ++i)
    {
        if(temp[i] != 0)
        {
            value += temp[i] * mul;
            mul *= 10;
        }
        else if(temp[i] == 0)
        {
            test.push_back(value);
            value = 0;
            mul = 1;
        }
    }    
    test.push_back(value);
    
    for(int i = 0; i < test.size(); ++i)
    {
        if(isprime(test[i]))
        {
            answer++;
        }        
    }        
    
    return answer;
}