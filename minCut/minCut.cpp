/*************************************************************************
	> File Name: minCut.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Mon 20 Jun 2016 11:07:15 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minCut(string s)
{
    int n = s.size();
    vector<vector<bool> > isPalin(n, vector<bool>(n, false));
    vector<int> min(n+1);  //min cut from end

    for(int i = 0; i<= n; i++)
        min[i] = n - i;
    
    for(int i = 0; i<n; i++){
        isPalin[i][i] = true;
    }
    for(int i = n-1; i>=0; i--){
        for(int j = i; j<n; j++){
            if(s[i] == s[j]){
                if(j-i<2 || isPalin[i+1][j-1] == true){
                    isPalin[i][j] = true;
                    if(min[i] > min[j+1] + 1)
                    min[i]  = min[j+1] + 1;
                }
            }
        }
    }
    return min[0]-1;
}

int main()
{
    string s;
    while(cin >> s){
        cout << minCut(s) << endl;
    }
}

