#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = -1;
vector<int> ans;
vector<vector<int>> Dungeons;
int totalSize;
int K;
int isused[10];

void Print()
{
    for(auto a : ans)
    {
        cout << a<<" ";
    }
    cout <<"\n";
}
void Check()
{
    int tempK = K;
    int tempAnswer = 0;
    
    for(int i = 0; i < ans.size(); ++i)
    {
        if(tempK >= Dungeons[ans[i]][0])
        {
            tempK -= Dungeons[ans[i]][1];
            tempAnswer++;
        }
        else
        {
            break;
        }
    }
    answer = max(tempAnswer, answer);
}

void Choose(int cur)
{
    if(cur == totalSize + 1)
    {
        Check();
        //Print();
        return;
    }
    for(int i = 0; i < totalSize; ++i)
    {
        if(!isused[i])
        {
            ans.push_back(i);
            isused[i] = 1;
            Choose(cur + 1);
            ans.pop_back();
            isused[i] = 0;
        }        
    }
}

int solution(int k, vector<vector<int>> dungeons) 
{    
    totalSize = dungeons.size();
    K = k;
    Dungeons = dungeons;
    Choose(1);    
    
    return answer;
}