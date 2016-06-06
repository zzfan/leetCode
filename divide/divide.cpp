/*************************************************************************
	> File Name: divide.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 15 Apr 2016 03:04:39 PM HKT
 ************************************************************************/

#include<iostream>
#include<limits>
using namespace std;

int divide(int dividend, int divisor)
{
    int sign = 1;
    if(dividend == 0) return 0;
    if(dividend < 0) sign *= -1;
    if(divisor < 0) sign *= -1;
    unsigned int dvd = dividend > 0 ? dividend : -dividend;
    unsigned int dvs = divisor > 0 ? divisor : -divisor;
    //abs function 
    //but abs(int_min) is int_min, not int_max + 1
    unsigned int inc[32];
    unsigned int migValue = dvs;
    int i = 0;

    while(migValue > 0 && migValue <= dvd){
        inc[i] = migValue;
        migValue = migValue << 1;
        i++;
    }
    i--;
    unsigned int res = 0;
    while(i >= 0 && dvd != 0){
        if(dvd >= inc[i]){
            dvd = dvd - inc[i];
            res += 1<<i;
        }
        i--;
    }
    if(sign > 0){
        if(res  == numeric_limits<int>::max() + 1)
        return res-1;
    }
    res *= sign;
    return res;
}

int main()
{
    int dividend, divisor;
    while(cin >> dividend >> divisor){
        cout << divide(dividend, divisor) << endl;
    }
    return 0;
}
