/*************************************************************************
	> File Name: lengthOfLastWord.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 06 Jul 2016 02:10:35 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s)
{
    if(s.size() < 1) return 0;
    int i = s.size()-1;
    //注意考虑这种情况
    while(s[i] == ' ') i--;
    int result = 0;
    while(s[i] != ' ' && i>=0){
        i--;
        result++;
    }
    return result;
}

int main()
{
    string s;
    while(getline(cin, s)){
        cout << lengthOfLastWord(s) << endl;
    }
}

