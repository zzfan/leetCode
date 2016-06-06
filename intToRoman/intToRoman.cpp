/*************************************************************************
	> File Name: intToRoman.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 30 Mar 2016 02:42:03 PM HKT
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

string intToRoman(int num)
{
    string str;
    string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    for(int i = 0; i<13; i++){
        while(num>=value[i]){
            num -= value[i];
            str += symbol[i];
        }
    }
    return str;
}

int main()
{
    int num;
    while(cin >> num){
        cout << intToRoman(num) << endl;
    }
}
