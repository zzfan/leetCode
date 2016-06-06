/*************************************************************************
	> File Name: romanToInt.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 30 Mar 2016 02:58:37 PM HKT
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

int romanToInt(string s){
    int integer=0;
    int offset=0;
    string temp;
    string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    for(int i = 0; i<s.size(); i++){
        temp.clear();
        temp += s[i];
        temp += s[i+1];
        for(offset=0; offset<13; offset++){
            if(temp == symbol[offset])
            break;
        }
        if(offset==13){
            temp.clear();
            temp += s[i];
            for(offset=0; offset<13; offset++){
                if(symbol[offset] == temp)
                break;
            }
            integer += value[offset];
        }
        else{
            integer += value[offset];
            i++;
        }
    }
    return integer;
}

int main()
{
    string test = "MMMIV";
    cout << romanToInt(test) << endl;
}
