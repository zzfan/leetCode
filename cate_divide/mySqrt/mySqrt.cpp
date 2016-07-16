/*************************************************************************
	> File Name: mySqrt.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Tue 14 Jun 2016 11:23:34 AM HKT
 ************************************************************************/

#include <iostream>
using namespace std;

int mySqrt(int x)
{
    if(x < 0) return -1;
    if(x == 0) return 0;
    int low = 1, high = x/2+1;
    int mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(x/mid >= mid && (mid+1) > x/(mid+1)){
            return mid;
        }else if(x/mid > mid){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
}

int main()
{
    int n;
    while(cin >> n){
        cout << mySqrt(n) << endl;
    }
}

