#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
vector<int> ans;
vector<vector<int>> DICE;

int maxWin = -1;
vector<int> answer;

void Calc(int cur, int currentSum, vector<int>& sum, vector<int>& inVec)
{
    if(cur == n/2)
    {
        sum.push_back(currentSum);
        return;
    }
    int idx = inVec[cur];
    
    for(int d : DICE[idx])
    {
        Calc(cur + 1, currentSum + d, sum, inVec);
    }
}

void Check()
{
    vector<int> A;
    vector<int> B;
    vector<bool> isused(n, false);
    
    for(int i = 0; i < ans.size(); ++i)
    {
        isused[ans[i]] = 1;
        A.push_back(ans[i]);
    }
    
    for(int i = 0; i < n; ++i)
    {
        if(!isused[i])
            B.push_back(i);
    }
   
    vector<int> sumA;
    vector<int> sumB;
    
    Calc(0, 0, sumA, A);
    Calc(0, 0, sumB, B);
    
    int win = 0;
    sort(sumB.begin(), sumB.end());

    for (int s : sumA) 
    {
        auto it = lower_bound(sumB.begin(), sumB.end(), s);
        win += (it - sumB.begin());
    }
    
    if(maxWin < win)
    {
        maxWin = win;
        answer.clear();
        for(int i = 0; i < A.size(); ++i)
        {
            answer.push_back(A[i] + 1);
        }
    }
}

void Choose(int cur, int st)
{
    if(cur == n/2)
    {
        Check();
        return;
    }
    
    for(int i = st; i < n; ++i)
    {
        ans.push_back(i);
        Choose(cur + 1, i + 1);
        ans.pop_back();   
    }
}

vector<int> solution(vector<vector<int>> dice) 
{    
    n = dice.size();
    DICE = dice;
    
    Choose(0, 0);    
    sort(answer.begin(), answer.end());
    
    return answer;
}