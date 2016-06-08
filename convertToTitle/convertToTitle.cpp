/*************************************************************************
	> File Name: convertToTitle.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 08 Jun 2016 09:38:59 AM HKT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string convertToTitle(int n)
{
    string result = "";
    while(n){
        result = (char)((n-1)%26+'A') + result;
        n = (n-1)/26;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << convertToTitle(n) << endl;
    return 0;
}

