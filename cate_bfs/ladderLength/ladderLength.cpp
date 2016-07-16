/*************************************************************************
	> File Name: ladderLength.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 24 Jun 2016 08:33:30 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

//这题很有意思，不知道从哪里下手
//BFS
//不能这么循环，因为会删光了
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
{
    if(beginWord.size() != endWord.size()) return 0;
    if(beginWord.empty() || endWord.empty()) return 0;

    queue<string> path;
    path.push(beginWord);
    int level = 1;
    wordList.erase(beginWord);
    while(wordList.size() >= 0 && !path.empty()){
        int len = path.size();
        for(int count = 0; count<len; count++){
            string curWord = path.front();
            path.pop();
            for(int i = 0; i<curWord.size(); i++){
                string tmp = curWord;
                for(char j = 'a'; j<='z'; j++){
                    if(tmp[i] == j) continue;
                    tmp[i] = j;
                    if(tmp == endWord) return level+1;
                    if(wordList.find(tmp) != wordList.end()) path.push(tmp);
                    wordList.erase(tmp);
                }
            }
        }
        level++;
    }
    return 0;
}

/*
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
{
    if(beginWord.size() != endWord.size()) return 0;
    if(beginWord.empty() || endWord.empty()) return 0;

    queue<string> path;
    path.push(beginWord);
    int level = 1;
    int count = 1;
    wordList.erase(beginWord);
    while(wordList.size() >= 0 && !path.empty()){
        string curWord = path.front();
        path.pop();
        count--;
        for(int i = 0; i<curWord.size(); i++){
            string tmp = curWord;
            for(char j = 'a'; j<='z'; j++){
                if(tmp[i] == j) continue;
                tmp[i] = j;
                if(tmp == endWord) return level+1;
                if(wordList.find(tmp) != wordList.end()) path.push(tmp);
                wordList.erase(tmp);
            }
        }
        if(count==0){
            count = path.size();
            level++;
        }
    }
    return 0;
}
*/

int main()
{
    string b = "hit";
    string e = "cog";
    unordered_set<string> w = {"hot", "dot", "dog", "lot", "log"};
    cout << ladderLength(b, e, w) << endl;
}

