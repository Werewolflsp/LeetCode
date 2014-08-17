/**********************************

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

**********************************/

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
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        for(auto it = intervals.begin(); it != intervals.end(); it++){
            insert(res, *it);
        }
        return res;
    }

    void insert(vector<Interval> &intervals, Interval newInterval) {
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
