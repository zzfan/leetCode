/*************************************************************************
	> File Name: isPalindrome.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 17 Jul 2016 11:00:49 AM HKT
 ************************************************************************/

#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    if(x < 0){
        return false;
    }
    else if(x == 0){
        return true;
    }

    int res = 0;
    int temp = x;
    while(x){
        res = res*10 + x%10;
        x = x/10;
    }
    if(res == temp) return true;
    else return false;
}

