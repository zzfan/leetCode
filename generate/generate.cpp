#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows)
{
    vector<vector<int> > result;
    vector<int> temp;

    for(int i = 0; i<numRows; i++){
        temp.clear();
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i)
                temp.push_back(1);
            else if(i > 1)
                temp.push_back(result[i-1][j-1]+result[i-1][j]);
        }
        result.push_back(temp);
    }

    return result;
}
