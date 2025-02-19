class Solution {
public:
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start_time;
        vector<int> end_time;
        int count = 0;
        int max_room = 0;

        for(int i=0;i<intervals.size();i++) {
            start_time.push_back(intervals[i][0]);
            end_time.push_back(intervals[i][1]);
        }

        sort(start_time.begin(), start_time.end());
        sort(end_time.begin(), end_time.end());

        int s=0,e=0;

        while(s<start_time.size()) {
            if(start_time[s]<end_time[e]) {
                count++;
                s++;
            } else {
                count--;
                e++;
            }

            if(count>max_room) max_room = count;
        }

        return max_room;

    }
};
