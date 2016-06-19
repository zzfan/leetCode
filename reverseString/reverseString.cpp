/*************************************************************************
	> File Name: reverseString.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 15 Jun 2016 10:31:42 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string reverseString(string s)
{
    int mid = (s.size()-1)/2;
    if((s.size()-1)%2){
        for(int i = 1; mid-i+1>=0&&mid+i<s.size(); i++){
            char temp = s[mid-i+1];
            s[mid-i+1] = s[mid+i];
            s[mid+i] = temp;
        }
    }
    else{
        for(int i = 0; mid-i>=0&&mid+i<s.size(); i++){
            char temp = s[mid-i];
            s[mid-i] = s[mid+i];
            s[mid+i] = temp;
        }
    }
    return s;
}

int main()
{
    string s;
    while(cin >> s){
        cout << reverseString(s) << endl;
    }
}

