/*************************************************************************
	> File Name: largestRectangleArea.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Mon 13 Jun 2016 01:56:31 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

//暴力解法，肯定过不了
//最大矩形的高度毫无疑问必然和某一个立柱的高度相等
int largestRectangleArea_force(vector<int>& heights)
{
    if(heights.size() == 0) return 0;
    int max = 0;
    for(int i = 0; i<heights.size(); i++){
        int mid = i;
        int area = 0;
        for(; mid>=0 && heights[mid]>=heights[i]; area += heights[i], --mid);
        for(mid = i+1; mid<=heights.size() && heights[mid]>=heights[i]; area += heights[i], ++mid);
        if(max < area) max = area;
    }
    return max;
}

//新的解法,非常好的一个想法
//用2 1 5 6 2 3推导下就行了，注意入栈的是下标不是高度
int largestRectangleArea(vector<int>& heights)
{
    if(heights.size() == 0) return 0;
    stack<int> st;
    int max = 0;
    heights.push_back(0);
    int leftarea = 0, rightarea = 0;
    for(int i = 0; i<heights.size(); ++i){
        while(!st.empty() && heights[st.top()] > heights[i]){
            int tmp = st.top();
            st.pop();
            leftarea = (st.empty() ? tmp+1 : tmp-st.top())*heights[tmp];
            rightarea = (i-tmp-1)*heights[tmp];
            if((leftarea + rightarea) > max) max = leftarea+rightarea;
        }
        st.push(i);
    }
    return max;
}

int main()
{
    int n;
    while(cin >> n){
        cin.get();
        vector<int> heights;
        string s;
        getline(cin, s);
        stringstream sp(s);
        for(int i = 0; i<n; i++){
            int temp;
            sp >> temp;
            heights.push_back(temp);
        }
        cout << largestRectangleArea(heights) << endl;
    }
}

