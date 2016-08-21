/*************************************************************************
	> File Name: climbStairs.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 21 Aug 2016 03:25:08 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//递归算法
int climbStairs1(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    return climbStairs1(n-1) + climbStairs1(n-2);
}

//动态规划
int climbStairs(int n)
{
    vector<int> res(n+1);
    res[0] = 1;
    res[1] = 1;
    for(int i = 2; i<=n; i++)
        res[i] = res[i-1] + res[i-2];
    return res[n];
}

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
}

