#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <sstream>
using namespace std;

//没有考虑重复的单词
vector<int> findSubstring_bak(string s, vector<string>& words)
{
    vector<int> result;
    int len = words.size();
    int strlen = words[0].size();
    if(s.size() == 0 || s.size() <len*strlen) return result;
    vector<bool> flag(len, false);
    for(int i = 0; i<s.size()-len*strlen; i++){
        int j;
        for(j = i; j-i<len*strlen; j = j+strlen){
            string temp = s.substr(j, strlen);
            vector<string>::iterator it;
            it = find(words.begin(), words.end(), temp);
            if(it != words.end()&&flag[it-words.begin()] == false){
                flag[it-words.begin()] = true;
            }
            else break;
        }
        if(strlen*len == j-i){
            result.push_back(i);
        }
        for(int k = 0; k<len; k++){
            flag[k] = false;
        }
    }
    return result;
}

//优化版本
bool checkSubstring(string s, int start, unordered_map<string, int>& wordCount, int wordsNum, int wordsLen)
{
    if(s.size()-start+1 < wordsNum*wordsLen) return false;
    int total = wordsNum*wordsLen;
    unordered_map<string, int> found;
    for(int i = 0; i<wordsNum; i++){
        string temp = s.substr(start+i*wordsLen, wordsLen);
        if(!wordCount.count(temp)) return false;
        found[temp]++;
        if(found[temp] > wordCount[temp]) return false;
    }
    return true;
}

vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> result;
    int wordsNum = words.size();
    int wordsLen = words[0].size();
    int totalLen = wordsNum*wordsLen;
    unordered_map<string, int> wordCount;
    for(int i = 0; i<wordsNum; i++){
        wordCount[words[i]]++;
    }

    for(int i = 0; i<=s.size()-totalLen; i++){
        if(checkSubstring(s, i, wordCount, wordsNum, wordsLen))
            result.push_back(i);
    }
    return result;
}

int main()
{
    string s, strs;
    vector<string> words;
    cin >> s;
    cin.get();
    getline(cin, strs);
    stringstream ss(strs);
    string temp;
    while(ss >> temp){
        words.push_back(temp);
    }
    vector<int> result = findSubstring(s, words);
    for(int i = 0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}
