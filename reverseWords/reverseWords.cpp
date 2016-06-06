/*************************************************************************
	> File Name: reverseWords.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 04 May 2016 07:38:39 AM HKT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void reverse(string& s, int l, int r)
{
    while(l < r){
        int temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

void reverseWords(string& s)
{
    if(s.size() == 0) return;
    reverse(s, 0, s.size()-1);
    int last = 0;
    int i = 0;
    for(i = 0; i<s.size(); i++){
        if(s[i] == ' '){
            reverse(s, last, i-1);
            last = i + 1;
        }
    }
    reverse(s, last, i-1);
}

int main()
{
    string s;
    while(getline(cin, s)){
        reverseWords(s);
        cout << s << endl;
    }
}

