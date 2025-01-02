#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
using namespace std;

void Print(vector<string> v1, vector<string> v2)
{
    for(auto v : v1)
    {
        cout << v <<" ";
    }
    cout <<"\n";
    for(auto v : v2)
    {
        cout << v <<" ";
    }
}
bool Check(string str)
{
    int cnt = 0;
    if(('a' <= str[0] && str[0] <= 'z') ||('A' <= str[0] && str[0] <= 'Z'))
    {
        cnt++;
    }
    if(('a' <= str[1] && str[1] <= 'z') ||('A' <= str[1] && str[1] <= 'Z'))
    {
        cnt++;
    }
    if(cnt == 2)
        return true;
    return false;
}

vector<string> makeArr(const string& str1)
{
    vector<string> vec;
    vector<string> res;
    
    for(int i = 0; i < str1.size() - 1; ++i)
    {
        vec.push_back(str1.substr(i, 2));
    }
    
    for(int i = 0; i < vec.size(); ++i)
    {
        if(Check(vec[i]))
        {
            string temp;
            if('a' <= vec[i][0] && vec[i][0] <= 'z')
            {
                vec[i][0] -= 32;
            }
            temp += vec[i][0];
            if('a' <= vec[i][1] && vec[i][1] <= 'z')
            {
                vec[i][1] -= 32;
            }
            temp += vec[i][1];
            
            res.push_back(temp);
        }
    }
    
    return res;
}

int solution(string str1, string str2) 
{
    float answer = 0;    
    
    vector<string> vec1;
    vector<string> vec2;
    unordered_map<string, int> um1;
    unordered_map<string, int> um2;
    set<string> s;
    
    vec1 = makeArr(str1);
    vec2 = makeArr(str2);
    
    int size1 = vec1.size();
    int size2 = vec2.size();
    
    float total = 0;
    float same = 0;
    
    //둘 다 공집합
    if(size1 == 0 && size2 == 0)
        answer = 1;
    else
    {
        for(const auto& v : vec1)
        {
            s.insert(v);
            um1[v]++;
        }

        for(const auto& v : vec2)
        {
            s.insert(v);
            um2[v]++;
        }

        for(auto it = s.begin(); it != s.end(); ++it)
        {
            int a = um1[*it];
            int b = um2[*it];
            
            if(a != 0 && b == 0)
                total += a;
            else if(a == 0 && b != 0)
                total += b;
            else if(a != 0 && b != 0)
            {
                if(a == b)
                {
                    total += a;
                    same += a;
                }
                else
                {
                    if(a > b)
                    {
                        total += a;
                        same += b;
                    }
                    else
                    {
                        total += b;
                        same += a;
                    }                    
                }
            }
        }
        //cout << total<< " " << same << "\n";
        answer = same/total;
    }    
            
    
    //Print(vec1, vec2);
    
    answer *= 65536;
    answer = floor(answer);
        
    return answer;
}