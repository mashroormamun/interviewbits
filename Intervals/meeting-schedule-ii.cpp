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

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start, end;

        for(int i=0;i<intervals.size();i++) {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int s=0, e=0;
        int count = 0, max = 0;

        while(s<start.size()) {
            if(end[e] <= start[s]) {
                count--;
                e++;
            } else {
                count++;
                s++;
            }

            max = count > max ? count : max;
        }

        return max;
    }
};


int main() {
    Solution s;
    
    vector<Interval> v;
    v.push_back(Interval(0,40));
    v.push_back(Interval(5,10));
    v.push_back(Interval(15,20));
    
    cout << s.minMeetingRooms(v) << endl;
    
    
    return 0;
}