/*************************************************************************
	> File Name: grayCode.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 21 Aug 2016 03:52:51 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> grayCode(int n)
{
    vector<int> res;
    if(n<0) return res;
    res.push_back(0);
    int cnt = 1;
    for(int i = 1; i<=n; i++){
        for(int j = res.size()-1; j>=0; j--)
            res.push_back(res[j]+cnt);
        cnt = cnt<<1;
    }
    return res;
}

