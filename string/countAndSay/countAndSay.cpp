/*************************************************************************
	> File Name: countAndSay.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Mon 04 Jul 2016 08:51:08 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string countAndSay(int n)
{
    //string result;
    string pre = "1";
    //result = result + pre;
    for(int i = 1; i<n; i++){
        int count = 1;
        char c = pre[0];
        string temp;
        //这个边界条件的考虑很重要
        pre.push_back('#');
        for(int j = 1; j<pre.size(); j++){
            if(c == pre[j]) count++;
            else{
                stringstream ss;
                ss << count << c;
                temp = temp + ss.str();
                count = 1;
                c = pre[j];
            }
        }
        pre = temp;
        //result = result + temp;
    }
    return pre;
}

int main()
{
    int n;
    while(cin >> n){
        cout << countAndSay(n) << endl;
    }
}


