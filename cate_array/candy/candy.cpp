/*************************************************************************
	> File Name: candy.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Thu 25 Aug 2016 09:25:51 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int candy(vector<int>& ratings)
{
    int len = ratings.size();
    vector<int> candys(len, 1);

    //从左往右扫描
    for(int i = 1; i<len; i++){
        if(ratings[i] > ratings[i-1])
            candys[i] = candys[i-1]+1;
    }
    //从右往左扫描
    for(int i = len-2; i>=0; i--){
        if(ratings[i] > ratings[i+1] && candys[i] <= candys[i+1])
            candys[i] = candys[i+1]+1;
    }
    int total = 0;
    for(int i = 0; i<len; i++)
        total += candys[i];
    return total;
}

