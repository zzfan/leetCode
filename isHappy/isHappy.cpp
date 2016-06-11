/*************************************************************************
	> File Name: isHappy.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 11 Jun 2016 05:42:04 PM HKT
 ************************************************************************/

#include <iostream>
#include <unordered_set>
using namespace std;

bool isHappy(int n)
{
    if(n<1) return false;
    if(n==1) return true;

    unordered_set<int> showedNums;
    showedNums.insert(n);

    while(true){
        int s = 0;
        while(n){
            s += (n%10)*(n%10);
            n = n/10;
        }
        if(s == 1) return true;
        else if(showedNums.find(s) != showedNums.end()) 
            return false;
        n = s;
        showedNums.insert(s);
    }
}

int main()
{
    int n;
    while(cin >> n){
        if(isHappy(n)) cout << "isHappy" << endl;
    }
}
