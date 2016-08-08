/*************************************************************************
	> File Name: longestConsecutive.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Tue 26 Apr 2016 10:50:06 AM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>
using namespace std;

//排序再找的话时间就超过了O(n)了
int longestConsecutive(vector<int>& nums)
{
    //把vector转化为哈希set
    unordered_set<int> hs;
    for(int i = 0; i<nums.size(); i++){
        hs.insert(nums[i]);
    }

    int maxLen = 0;
    for(int i = 0; i<nums.size(); i++){
        int curLen = 1;
        int curNum = nums[i];
        if(hs.find(curNum) != hs.end()){
            int nNum = curNum + 1;
            //考虑递增
            while(hs.find(nNum) != hs.end()){
                hs.erase(nNum);
                curLen++;
                nNum++;
            }

            //考虑递减
            nNum = curNum - 1;
            while(hs.find(nNum) != hs.end()){
                hs.erase(nNum);
                curLen++;
                nNum--;
            }

            if(maxLen < curLen) maxLen = curLen;
        }
    }
    return maxLen;
}

int main()
{
    vector<int> temp;
    string s;
    while(getline(cin, s)){
        stringstream sp(s);
        temp.clear();
        int teger;
        while(sp >> teger){
            temp.push_back(teger);
        }
        cout << longestConsecutive(temp) << endl;
    }
}

