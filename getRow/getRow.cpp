#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> result(rowIndex+2, 0);

    result[1] = 1;
    for(int i = 0; i<rowIndex; i++){
        for(int j = rowIndex+1; j>0; j--){
            result[j] = result[j-1] + result[j];
        }
    }
    result.erase(result.begin());
    return result;
}
    
