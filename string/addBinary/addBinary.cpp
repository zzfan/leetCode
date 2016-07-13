/*************************************************************************
	> File Name: addBinary.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 02 Jul 2016 10:24:22 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/*
 * Given two binary strings, return their sum(also a binary string).
 * For example: a = "11"  b = "1"  Return "100".
 */
string addBinary(string a, string b)
{
    int temp, flag = 0;
    int i = a.size()-1, j = b.size()-1;
    string result;

    while(i >= 0 || j >= 0){
        temp = 0;
        if(i >= 0) {
            temp += a[i] - '0';
            i--;
        }
        if(j >= 0) {
            temp += b[j] - '0';
            j--;
        }
        temp += flag;
        int val = temp%2;
        result.insert(result.begin(), val+'0');
        flag = temp/2;
    }
    if(1 == flag) result.insert(result.begin(), '1');
    return result;
}

int main()
{
    string a = "11", b = "1";
    cout << addBinary(a, b) << endl;
}
