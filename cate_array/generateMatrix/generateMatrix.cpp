#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > generateMatrix(int n)
{
    vector<vector<int> > ret(n, vector<int> (n, 0));
    if(n == 0) return ret;
    int value = 1;
    for(int i = 0; i<n/2; i++){
        int last = n-1-i;
        for(int j = i; j<last; j++){
            ret[i][j] = value;
            value++;
        }
        for(int j = i; j<last; j++){
            ret[j][last] = value;
            value++;
        }
        for(int j = last; j>i; j--){
            ret[last][j] = value;
            value++;
        }
        for(int j = last; j>i; j--){
            ret[j][i] = value;
            value++;
        }
    }
    if(n%2) ret[n/2][n/2] = value;
    return ret;
}
