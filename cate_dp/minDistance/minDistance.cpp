/*************************************************************************
	> File Name: minDistance.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sun 04 Sep 2016 12:39:26 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance(string word1, string word2)
{
    int m = word1.size(), n = word2.size();
    vector<vector<int> > d(m+1, vector<int> (n+1, 0));
    for(int i = 0; i<=n; i++){
        d[0][i] = i;
    }

    for(int i = 1; i<=m; i++){
        d[i][0] = i;
        for(int j = 1; j<=n; j++){
            d[i][j] = d[i-1][j-1];
            if(word1[i-1] != word2[j-1]) d[i][j]++;
            d[i][j] = min(min(d[i-1][j]+1, d[i][j-1]+1), d[i][j]);
        }
    }
    return d[m][n];
}

