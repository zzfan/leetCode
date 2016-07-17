/*************************************************************************
	> File Name: insert.cpp
	> Author: zzfan
	> Mail: zzfan@mail.ustc.edu.cn 
	> Created Time: Sat 16 Jul 2016 09:38:00 PM HKT
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

//这道题需要注意的点很多:
//如果不相交直接插入即可，但是如果相交得继续判断和下一个是否相交
//而且得注意
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
    vector<Interval> res;
    bool isInsert = false;
    for(int i = 0; i<intervals.size(); i++){
        if(isInsert){
            res.push_back(intervals[i]);
            continue;
        }

        //如果不想交
        if(newInterval.end < intervals[i].start){
            res.push_back(newInterval);
            isInsert = true;
        }
        //相交,注意相交条件
        if(newInterval.start <= intervals[i].end && intervals[i].start <= newInterval.end){
            newInterval.start = newInterval.start < intervals[i].start ? newInterval.start : intervals[i].start;
            newInterval.end = newInterval.end > intervals[i].end ? newInterval.end : intervals[i].end;
            continue;
        }
        res.push_back(intervals[i]);
    }
    if(!isInsert) res.push_back(newInterval);
    return res;
}

