/*************************************************************************
	> File Name: canCompleteCircuit.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 23 Apr 2016 09:12:21 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    //超时了
    int res_gas = 0;
    int N = gas.size();
    int i,j;
    if(N <= 1)
        return N;
    for(i = 0; i<N; i++){
        res_gas = 0;
        for(j = 0; j < N; j++){
            res_gas += gas[(i+j)%N];
            if(res_gas < cost[(i+j)%N]) break;
            res_gas -= cost[(i+j)%N];
        }
        if(j==N) return i;
    }
    return -1;
}

int canCompleteCircuit_fork(vector<int>& gas, vector<int> cost)
{
    //我只能说这个方法很吊
    //而且这题利用了解法唯一这个条件
    vector<int> diff(gas.size());
    for(int i = 0; i<gas.size(); i++){
        diff[i] = gas[i] - cost[i];
    }

    int leftGas = 0, sum = 0, startnode = 0;
    for(int i = 0; i<gas.size(); i++){
        leftGas += diff[i];
        sum += diff[i];
        if(sum < 0){
            startnode = i+1;
            sum = 0;
        }
    }
    if(leftGas < 0) return -1;
    else return startnode;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {1, 2, 3, 4, 5};
    cout << canCompleteCircuit(gas, cost) << endl;
    cout << canCompleteCircuit_fork(gas, cost) << endl;
    return 0;
}

