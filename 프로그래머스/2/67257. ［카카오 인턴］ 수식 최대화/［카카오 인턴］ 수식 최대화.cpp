#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

//* + - -> 0 1 2
//우선순위 구하고, 계산하고 
//백트래킹, 계산은 string 배열에 분리해서 두고
// -  *  -   + 
//a  b  c  d  e
//* + -

int isused[3];
char oper[3] = {'*', '+', '-'};

vector<char> ans;
vector<long long> nums;
vector<char> ops;
long long answer = 0;

void Print(vector<char> vec)
{
    for(const auto v : vec)
        cout<<v <<" ";
}

long long calculate(long long a, long long b, char op)
{
    if(op == '+')
        return a + b;
    if(op == '-')
        return a - b;
    if(op == '*')
        return a * b;
}

void Check()
{
    int temp = 0;
    vector<long long> nums_temp = nums;
    vector<char> ops_temp = ops;
    
    for(const auto& a : ans)
    {
        bool flag = false;
        for(int i = 0; i < ops_temp.size(); ++i)
        {
            if(ops_temp[i] == a)
            {
                flag = true;  
                long long res = calculate(nums_temp[i], nums_temp[i+1], a);          
                nums_temp[i] = res;
                nums_temp.erase(nums_temp.begin() + i + 1);
                ops_temp.erase(ops_temp.begin() + i);
                
                i--;
            }
        }
        if(nums_temp.size() == 1)
            answer = max(answer, abs(nums_temp[0]));
    }    
}

void Choose(int cur)
{
    if(cur == 3)
    {
        Check();
        return;
    }
    
    for(int i = 0; i < 3; ++i)
    {
        if(!isused[i])
        {
            isused[i] = 1;
            ans.push_back(oper[i]);
            Choose(cur + 1);
            isused[i] = 0;
            ans.pop_back();
        }
    }   
}

long long solution(string expression) 
{    
    string temp_num = "";
    
    for(auto e : expression)
    {
        if(isdigit(e))
        {
            temp_num += e;        
        }
        else
        {
            nums.push_back(stoll(temp_num));
            temp_num = "";
            ops.push_back(e);
        }
    }
    if(!temp_num.empty())        
        nums.push_back(stoll(temp_num));
    
    Choose(0);
    
    return answer;
}