/*************************************************************************
	> File Name: diffWaysToCompute.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 08 Jun 2016 08:59:37 AM HKT
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> diffWaysToCompute(string input)
{
    vector<int> result;
    int len = input.size();
    for(int k = 0; k<len; k++){
        if(input[k] == '+' || input[k] == '-' || input[k] == '*'){
            vector<int> result1 = diffWaysToCompute(input.substr(0,k));
            vector<int> result2 = diffWaysToCompute(input.substr(k+1));
            for(vector<int>::iterator i = result1.begin(); i != result1.end(); i++)
            for(vector<int>::iterator j = result2.begin(); j != result2.end(); j++){
                if(input[k] == '+')
                    result.push_back(*i + *j);
                else if(input[k] == '-')
                    result.push_back(*i - *j);
                else
                    result.push_back((*i)*(*j));
            }
        }
    }
    if(result.empty())
        result.push_back(atoi(input.c_str()));
    return result;
}

int main()
{
    string input;
    vector<int> vec;
    getline(cin, input);
    vec = diffWaysToCompute(input);

    for(int i = 0; i<vec.size(); i++){
        cout << vec[i] << ' ';
    }
    cout << endl;
}

