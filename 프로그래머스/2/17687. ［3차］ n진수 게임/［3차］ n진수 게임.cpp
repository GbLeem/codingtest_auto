#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string check(int temp)
{
    if (temp == 10)
    {
        return "A";
    }
    else if (temp == 11)
    {
        return "B";
    }
    else if (temp == 12)
    {
        return "C";
    }
    else if (temp == 13)
    {
        return "D";
    }
    else if (temp == 14)
    {
        return "E";
    }
    else if (temp == 15)
    {
        return "F";
    }
    else return "Z";
}

string change(int cur, int n)
{
    string res;
    while (cur >= n)
    {
        int temp = cur % n;

        if (check(temp) != "Z")
        {
            res += check(temp);
        }
        else
            res += to_string(cur % n);
        cur /= n;
    }
    if (check(cur) != "Z")
    {
        res += check(cur);
    }
    else
        res += to_string(cur);

    reverse(res.begin(), res.end());

    return res;
}

string solution(int n, int t, int m, int p)
{
    string answer = "";
    //0부터 n진법으로 나열해서
    //m중에 p번째 숫자만 넣어서
    //answer의 크기가 t가 될 때 까지
    //반복하기

    //0 1 2 3 4 5 6 7 8 9 10
    //m명 중 p번 인데 t개 구해야 하면, 

    int cur = 0;
    int length = 0;
    int idx = p;
    string total;
    while (answer.size() != t)
    {
        string temp;
        temp = change(cur, n); //0 1 10 11 100
        length += temp.size();
        total += temp;

        if (length >= idx)
        {
            answer += total[idx - 1];
            idx += m;
        }

        cur++;
    }

    return answer;
}