/*************************************************************************
	> File Name: myPow.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 15 Jul 2016 04:16:09 PM HKT
 ************************************************************************/

#include <iostream>
using namespace std;

double power(double x, int n){
    if(n == 0) return 1;
    double v = power(x, n/2);
    if(n%2 == 0) return v*v;
    else return v*v*x;
}

double myPow(double x, int n){
    if(n < 0) return 1.0/power(x, -n);
    else return power(x,n);
}

