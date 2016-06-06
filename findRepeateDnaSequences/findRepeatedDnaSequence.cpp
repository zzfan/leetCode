/*************************************************************************
	> File Name: findRepeatedDnaSequence.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 24 Apr 2016 10:38:24 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

vector<string> findRepeatedDnaSequence(string s)
{
    //基本的方法
    vector<string> result;
    unordered_set<string> repeat;

    for(int i = 0; i+9 < s.size(); i++){
        string t(s, i, 10);
        unordered_set<string>::iterator it = repeat.find(t);
        if(it != repeat.end()){
            if(find(result.begin(), result.end(), t) == result.end())
                result.push_back(t);
        } 
        else
            repeat.insert(t);
    }
    return result;
}

//新的方法，这个方法是抄袭的
#define eraser 0x3ffff
vector<string> findRepeatedDnaSequence_new(string s){
    vector<string> answer;
    int hint = 0; //存储长度为10的子串翻译后的int值
    if (s.size() < 10)
        return answer;
    unordered_set<unsigned int> repeated, check;//check用于防止重复答案
    unordered_map<char, unsigned int> ati{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    for(int i = 0; i != 10; i++){
        hint = (hint << 2) + ati[s[i]];//用s的前10个碱基构造的出事hint值
    }
    repeated.insert(hint);
    for(int i = 10; i != s.size(); i++){
        hint = ((hint & eraser) << 2) + ati[s[i]];
        unordered_set<unsigned int>::iterator it = repeated.find(hint);
        if(it != repeated.end()){
            it = check.find(hint);
            if(it == check.end()){
                answer.push_back(string(s, i-9, 10));
                check.insert(hint);
            }
        }
        else
            repeated.insert(hint);
    }
    return answer;
}

int main()
{
    string s;
    while(cin >> s){
        vector<string> result = findRepeatedDnaSequence_new(s);
        for(int i = 0; i<result.size(); i++){
            cout << result[i] << endl;
        }
    }
    return 0;
}
