/*************************************************************************
	> File Name: isPalindrome.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 24 Jun 2016 07:48:09 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//这个变型有点意思，很关键

bool isValid(char a)
{
    if((a >= 'a' && a <= 'z') || (a >= 'A' &&  a <= 'Z')) 
    return true;
    if(a >= '0' && a <= '9') return true;
    return false;
}

bool isEqual(char a, char b)
{
    if(a == b) return true;
    if(a < '0' || a > '9'){
        if((a-'a')==(b-'A')) return true;
        if((a-'A') == (b-'a')) return true;
    }
    return false;
}

bool isPalindrome(string s)
{
    if(s.size() == 0) return true;
    int low = 0, high = s.size()-1;
    while(low < high){
        while(!isValid(s[low]) && low < high) low++;
        while(!isValid(s[high]) && low < high) high--;
        if(low >= high) return true;
        if(isEqual(s[low], s[high])){
            low++;
            high--;
        }
        else return false;
    }
    return true;
}

int main()
{
    string s;
    while(getline(cin, s)){
        cout << isPalindrome(s) << endl;
    }
}

