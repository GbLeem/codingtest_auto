#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> answer;
unordered_map<string, string> um;
vector<pair<string, string>> vec;

vector<string> temp[100'002];


vector<string> split(string input, string delimiter) 
{
    vector<string> ret;    
    long long pos = 0;    
    string token = "";    
    
    while((pos = input.find(delimiter)) != string::npos) 
    {        
        token = input.substr(0, pos);        
        ret.push_back(token);        
        input.erase(0, pos + delimiter.length());    
    }    
    
    ret.push_back(input);    
    return ret;
}

vector<string> solution(vector<string> record) 
{    
    int size = record.size();
    
    for(int i = 0; i < record.size(); ++i)
    {
        temp[i] = split(record[i], " ");
    }    
    
    //enter uid muzi
    for(int i = 0; i < size; ++i)
    {        
        if(temp[i][0] == "Enter")
        {
            vec.push_back({temp[i][0], temp[i][1]}); //정보, ID
            um[temp[i][1]] = temp[i][2]; //ID 이름
        }
        if (temp[i][0] == "Leave")
        {
            vec.push_back({ temp[i][0], temp[i][1] });
        }
        if(temp[i][0] == "Change")
        {
            um[temp[i][1]] = temp[i][2];
        }                         
    }
    
    for(int i = 0; i < vec.size(); ++i)
    {
        string answerStr = "";
        answerStr += um[vec[i].second];
        
        if(vec[i].first == "Enter")
        {            
            answerStr += "님이 들어왔습니다.";
        }
        else
        {
            answerStr += "님이 나갔습니다.";
        }
        
        answer.push_back(answerStr);
    }
    
    
    return answer;
}