/*************************************************************************
	> File Name: wordBreak.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 07 Sep 2016 10:19:09 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

void findWordBreak(string &s, unordered_set<string> &dict, int start, vector<string> &sol, vector<bool> &possible, vector<string> &sentences){
    if(start == s.size() && !sol.empty()){
        string temp = sol[0];
        for(int i = 1; i<sol.size(); i++){
            temp = temp + " " + sol[i];
        }
        sentences.push_back(temp);
    }

    string word;
    for(int i = start; i<s.size(); i++){
        word.push_back(s[i]);
        //这个方法真是厉害，剪纸剪得很好
        if(dict.count(word) != 0 && possible[i+1]){
            sol.push_back(word);
            int oldsize = sentences.size();
            findWordBreak(s, dict, i+1, sol, possible, sentences);
            if(sentences.size() == oldsize) possible[i+1] = false;
            sol.pop_back();
        }
    }
}

vector<string> wordBreak(string s, unordered_set<string> &wordDict)
{
    vector<string> sentences;
    vector<string> sol;
    vector<bool> possible(s.size()+1, true);
    findWordBreak(s, wordDict, 0, sol, possible, sentences);
    return sentences;
}

