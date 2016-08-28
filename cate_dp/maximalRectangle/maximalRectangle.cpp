/*************************************************************************
	> File Name: maximalRectangle.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 27 Aug 2016 10:36:36 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int> height)
{
    //这里犯了一个错误，就是先求大小在push0了
    //最近老是反一些低级错误
    vector<int> temp;
    height.push_back(0);

    int m = height.size();
    int sum = 0;
    int i = 0;
    while(i<m){
        //维持递增序列，但是序列中左边的比自己高的不在序列中
        //也就是每一个矩形是左右两边比自己要高的
        if(temp.empty() || height[i] > height[temp.back()]){
            temp.push_back(i);
            i++;
        }
        else{
            int t = temp.back();
            temp.pop_back();
            sum = max(sum, height[t]*(temp.empty() ? i : i-1-temp.back()));
        }
    }
    return sum;
}

int maximalRectangle(vector<vector<char> > &matrix)
{
    //直方图
    if(matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();

    vector<vector<int> > count(m, vector<int> (n, 0));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(matrix[i][j] == '0'){
                count[i][j] = 0;
            }
            else{
                count[i][j] = (i==0) ? 1 : count[i-1][j] + 1;
            }
        }
    }
    int maxValue = 0;
    for(int i = 0; i<m; i++){
        maxValue = max(maxValue, maxArea(count[i]));
    }
    return maxValue;
}

int main()
{
    vector<vector<char> > test = {{'1'},{'1'},{'1'}};
    int res = maximalRectangle(test);
    cout << res << endl;
}

