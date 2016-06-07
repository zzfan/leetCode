/*************************************************************************
	> File Name: isPowerOfFour.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Mon 06 Jun 2016 11:15:21 AM HKT
 ************************************************************************/

#include <iostream>
using namespace std;

//之前有讨论过判断是不是2的幂，直接判断
//n&(n-1)是不是等于0
bool isPowerOfFour(int num)
{
    if((num&(num-1)) == 0){
        if(num&0x55555555){
            return true;
        }
    }
    return false;
}
