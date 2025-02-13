#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool comp(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int start = -1;

        for(int i=0;i<intervals.size();i++) {
            cout << intervals[i].start << "-" << intervals[i].end << endl;
            if(start > intervals[i].start) return false;
            start = intervals[i].end;
        }

        return true;
    }
};


int main() {
    Solution s;
    
    vector<Interval> v;
    v.push_back(Interval(3,6));
    v.push_back(Interval(1,2));
    v.push_back(Interval(8,9));
    
    cout << s.canAttendMeetings(v);
    
    
    return 0;
}