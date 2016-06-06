/*************************************************************************
	> File Name: multiply.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Tue 19 Apr 2016 03:01:10 PM HKT
 ************************************************************************/

#include<iostream>
#include <vector>
#include <string>
using namespace std;

string multiply(string num1, string num2)
{
    int n1 = num1.size(), n2 = num2.size();
    vector<int> temp(n1+n2, 0);
    int k = n1 + n2 -2;

    for(int i = 0; i<n1; i++){
        for(int j = 0; j<n2; j++){
            temp[k-i-j] += (num1[i] - '0')*(num2[j] - '0');
        }
    }

    int bittemp = 0;
    for(int i = 0; i<n1+n2; i++){
        temp[i] += bittemp;
        bittemp = temp[i]/10;
        temp[i] = temp[i]%10;
    }

    int i = n1 + n2 -1;
    while(temp[i] == 0) i--;
    if(i < 0) return "0";
    string res;
    for( ; i>=0; i-- ){
        res.push_back(temp[i] + '0');
    }
    return res;
}

int main()
{
    string num1, num2;
    while(cin >> num1 >> num2){
        cout << multiply(num1, num2) << endl;
    }
    return 0;
}


