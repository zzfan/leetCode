/*************************************************************************
	> File Name: backSolve.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 14 Jul 2016 02:43:54 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//回溯发，超时
int backSolve(int m, int n)
{
    if(m < 1 || n < 1) return 0;
    if(m == 1 || 1 == n) return 1;
    return backSolve(m-1, n) + backSolve(m, n-1);
}

int main()
{
    int m,n;
    cin >> m >> n;
    cout << backSolve(m, n) << endl;
}

