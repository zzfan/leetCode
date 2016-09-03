/*************************************************************************
	> File Name: isInterleave.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 03 Sep 2016 09:52:46 AM HKT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
    int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
    if(len1 + len2 != len3) return false;
    vector<vector<bool> > m(len1+1, vector<bool> (len2+1, false));
    m[0][0] = true;

    for(int i = 1; i<=len1; i++){
        if(s1[i-1] == s3[i-1])
            m[i][0] = true;
        else
            break;
    }
    for(int i = 1; i<=len2; i++){
        if(s2[i-1] == s3[i-1])
            m[0][i] = true;
        else
            break;
    }

    for(int i = 1; i<=len1; i++){
        for(int j = 1; j<=len2; j++){
            if(s1[i-1] == s3[i+j-1]){
                m[i][j] = m[i-1][j];
            }
            if(s2[j-1] == s3[i+j-1]){
                m[i][j] = m[i][j-1];
            }
        }
    }
    return m[len1][len2];
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if(isInterleave(s1, s2, s3)){
        cout << "yes" << endl;
    }
}

