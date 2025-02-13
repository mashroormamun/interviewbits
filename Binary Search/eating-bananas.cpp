#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int eatingDuration(vector<int>& piles, int speed) {
        double totalTime=0.0;

        for(int i=0;i<piles.size();i++) {
            double time = (double)piles[i]/(double)speed;
            time = time < 1.0 ? 1.0 : ceil(time);

            totalTime += time;
        }

        return (int) totalTime;
    }

    int findMax(vector<int>& v) {
        int max = INT_MIN;

        for(int i=0;i<v.size();i++) {
            max = max > v[i] ? max : v[i];
        }

        return max;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max = findMax(piles);

        if(piles.size() == h) return max;

        int left = 1;
        int right = max;
        int mid = left + (right-left)/2;

        int min = INT_MAX;

        while(left<right) {
            mid = left + (right-left)/2;
            int ed = eatingDuration(piles, mid);

            //cout << "-- " << left << " " << right << " " << mid << " " << ed << endl;

            if (ed <= h) {
                min = min > mid ? mid : min;
            }

            if(ed == h) break;

            if(ed > h) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        return min;
    }
};

int main() {
    vector<int> v{873375536,395271806,617254718,970525912,634754347,824202576,694181619,20191396,886462834,442389139,572655464,438946009,791566709,776244944,694340852,419438893,784015530,588954527,282060288,269101141,499386849,846936808,92389214,385055341,56742915,803341674,837907634,728867715,20958651,167651719,345626668,701905050,932332403,572486583,603363649,967330688,484233747,859566856,446838995,375409782,220949961,72860128,998899684,615754807,383344277,36322529,154308670,335291837,927055440,28020467,558059248,999492426,991026255,30205761,884639109,61689648,742973721,395173120,38459914,705636911,30019578,968014413,126489328,738983100,793184186,871576545,768870427,955396670,328003949,786890382,450361695,994581348,158169007,309034664,388541713,142633427,390169457,161995664,906356894,379954831,448138536};

    Solution s;

    // for(int i=1;i<10;i++) {
    //     cout << s.eatingDuration(v, i) << endl;
    // }

    cout << s.minEatingSpeed(v,943223529) << endl;

    return 0;
}
