/*************************************************************************
	> File Name: myAtio.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 30 Mar 2016 09:18:54 AM HKT
 ************************************************************************/

#include<iostream>
#include <string>
#include <cmath>
#include <limits>
using namespace std;

int myAtio(string str)
{
    //一定要记得初始化
    int temp=0;
    unsigned long long integer=0;
    int start =0;
    int len = str.size();
    bool positive = true;
    
    //各种情况都需要考虑到
    if(len == 0)
        return 0;

    for(start; start<len; start++){
        if(str[start] == ' ')
            continue;
        break;
    }

    if(str[start] == '-' || str[start] == '+'){
        if(str[start+1] < '0' || str[start+1] >'9' || start+1 >=len)
            return 0;
        if(str[start] == '-')
            positive = false;
        start++;
    }

    for(int j=start; j<len; j++){
        if(str[j] < '0' || str[j] > '9'){
            break;
        }
        else{
            temp = str[j] - '0';
            integer = integer*10 + temp;
            if(integer > (unsigned long long)numeric_limits<int>::max())
            return positive ? numeric_limits<int>::max() : numeric_limits<int>::min();
        }
    }

    if(positive)
        return integer;
    else 
        return integer*(-1);
}

int main()
{
    string test;
    int integer;
    while(getline(cin, test)){
        //只有在getline之前有cin操作的需要添加下面一行代码
//        cin.get();
        integer = myAtio(test);
        cout << integer << endl; 
    }
}
