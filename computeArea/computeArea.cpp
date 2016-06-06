/*************************************************************************
	> File Name: computeArea.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Fri 22 Apr 2016 09:52:42 AM HKT
 ************************************************************************/

#include<iostream>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int area = (C-A)*(D-B) + (G-E)*(H-F);
    if(E >= C || A >= G || B >= H || F >= D) return area;
    return area - ((min(C,G) - max(A,E))*(min(D,H) - max(B,F)));
}
