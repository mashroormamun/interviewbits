class Solution {
public:
    int mySqrt(int x) {
        if (x==0) return 0;
        if (x==1) return 1;

        long long int left = 0;
        long long int right = x;
        long long int target = x;
        long long int middle;

        while(left <= right) {
            long long int middle = left - (left-right)/2;

            if (middle * middle == target) {
                return middle;
            }

            if (middle * middle > target) {
                right = middle-1;
            }

            if (middle * middle < target) {
                left = middle+1;
            }

        }

        return right;
    }
};
