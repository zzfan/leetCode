/*************************************************************************
	> File Name: maxProfit.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 28 Aug 2016 04:44:18 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices)
{
    if(prices.empty()) return 0;
    int m = prices.size();
    vector<int> leftProfit(m, 0);
    int lmax = 0, minl = prices[0];
    for(int i = 1; i<m; i++){
        if(prices[i]<minl) minl = prices[i];
        else{
            lmax = max(lmax, prices[i]-minl);
        }
        leftProfit[i] = lmax;
    }

    int res = leftProfit[m-1];
    int rmax = 0, maxr = prices[m-1];
    for(int i = m-2; i>=0; i--){
        if(prices[i] > maxr) maxr = prices[i];
        else
            rmax = max(rmax, maxr-prices[i]);
        res = max(res, leftProfit[i]+rmax);
    }
    return res;
}

