/*************************************************************************
	> File Name: reverse.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 17 Jul 2016 10:23:56 AM HKT
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define INT_MIN 0x80000000
#define INT_MAX 0x7fffffff

int reverse(int x)
{
    unsigned long long res;
    unsigned long long xx;
    if(x == INT_MIN){
        xx = (unsigned long long)(INT_MAX)+1;
    }
    else{
        xx = x>0 ? x:-x;
    }
    res = 0;
    while(xx){
        res = res*10 + xx%10;
        xx = xx/10;
    }
    if((x>0 && res > (unsigned long long)(INT_MAX)) || (x<0 && res > (unsigned long long)(INT_MAX)+1))
    return 0;
    return x>0 ? res : -res;
}


