/*************************************************************************
	> File Name: simplifyPath.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Wed 06 Jul 2016 12:49:19 PM HKT
 ************************************************************************/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string simplifyPath(string path)
{
    string result;
    stack<string> sp;
    int lflag, rflag;
    int i = 0;
    while(i < path.size()){
        string temp;
        while('/' == path[i] && i<path.size()) i++;
        lflag = i;
        while(path[i] != '/' && i<path.size()) i++;
        rflag = i;
        //最后都是"//"的情况
        if(lflag == rflag) break;
        temp = path.substr(lflag, rflag-lflag);
        if(temp == ".."){
            if(sp.empty()){
                i++;
                continue;
            }
            else
                sp.pop();
        }
        else if(temp == "."){
            continue;
        }
        else{
            sp.push(temp);
        }
        i++;
    }
    if(sp.empty()) return "/";
    while(!sp.empty()){
        result = sp.top() + result;
        result = "/" + result;
        sp.pop();
    }
    return result;
}

int main()
{
    string s;
    while(getline(cin, s)){
        cout << simplifyPath(s) << endl;
    }
}



