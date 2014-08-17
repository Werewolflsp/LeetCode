/************************************

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

************************************/

#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int index = search(intervals, newInterval, 0, intervals.size()-1);

        bool inserted = false;
        for(auto it = intervals.begin() + index; it != intervals.end();){
            if(it->start > newInterval.end){
                break;
            }
            else if(it->end < newInterval.start){
                it++;
            }
            else{
                newInterval.start = min(it->start, newInterval.start);
                newInterval.end = max(it->end, newInterval.end);
                it = intervals.erase(it);
            }
        }

        for(int i = index - 1; i >= 0; i--){
            if(intervals[i].start > newInterval.end){
                continue;
            }
            else if(intervals[i].end < newInterval.start){
                intervals.insert(intervals.begin() + i + 1, newInterval);
                inserted = true;
                break;
            }
            else{
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
                intervals.erase(intervals.begin()+i);
            }
        }

        if(!inserted){
            intervals.insert(intervals.begin(), newInterval);
        }

        return intervals;
    }

    int search(const vector<Interval>& intervals, Interval newInterval, int i, int j){
        if(i >= j){
            j = max(j, 0);
            if(intervals.size() > 0 && intervals[j].end < newInterval.start){
                return (j+1);
            }
            else{
                return j;
            }
        }
        else{
            int index = (i+j)/2;
            if(intervals[index].start > newInterval.end){
                return search(intervals, newInterval, i, index-1);
            }
            else if(intervals[index].end < newInterval.start){
                return search(intervals, newInterval, index+1, j);
            }
            else{
                return index;
            }
        }
    }
};
