#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

/*
Input: "A man, a plan, a canal: Panama"
Output: true

Input: "race a car"
Output: false
*/

bool isPalindrome(string s) {
    int left=0;
    int right=s.length()-1;

    while(left<=right) {
        while(left<=right && isalpha(s[left])==0) {
            left++;
        }

        while(left<=right && isalpha(s[right])==0) {
            right--;
        }

        if(left>right) break;

        if(tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;

    }

    return true;
}

int longest_substring_without_repeating_characters(string s) {
    unordered_map<char, bool> m;

    int max=0;
    int local_max=0;
    queue<char> q;

    for(int i=0;i<s.length();i++) {
        if(m.find(s[i])==m.end()){
            m[s[i]] = true;
            q.push(s[i]);
        } else {
            while(!q.empty()) {
                char c = q.front();
                if(c!=s[i]) {
                    q.pop();
                    m.erase(c);
                } else {
                    q.pop();
                    q.push(s[i]);
                    break;
                }
            }
        }

        max = max < q.size() ? q.size() : max;
    }

    return max;

}

    int binary_search(vector<int>& nums, int start, int end, int target) {
        while(start<=end) {
            int mid = start + (end-start)/2;

            if(nums[mid] == target) return mid;

            if(nums[mid] < target) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        return -1;
    }

    int left_binary_search(vector<int>& nums, int end, int target) {
        if(nums[0]==target) return 0;
        
        int start=0;

        while(start<=end) {
            int mid = start + (end-start)/2;

            if(nums[mid] == target && nums[mid-1]!=target) return mid;

            if(nums[mid] < target) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        return -1;
    }

    int right_binary_search(vector<int>& nums, int start, int target) {
        int end=nums.size()-1;

        if(nums[end]==target) return end;
        
        while(start<=end) {
            int mid = start + (end-start)/2;

            if(nums[mid] == target && nums[mid+1]!=target) return mid;

            if(nums[mid] <= target) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int index = binary_search(nums, 0, nums.size()-1, target);
        cout << index << endl;

        if(index == -1) return vector<int>{-1,-1};
        
        int left_index = left_binary_search(nums, index, target);
        cout << left_index << endl;

        int right_index = right_binary_search(nums, index, target);
        cout << right_index << endl;

        cout << left_index << " " << right_index << endl;

        return vector<int>{left_index, right_index};
    }

bool canPartition(vector<int> nums) {
    set<int> s{0};
    int sum = 0;
    for(int i=0;i<nums.size();i++) {
        sum += nums[i];
    }

    if(sum%2==1) return false;
    
    int target = sum/2;

    for(int i=0;i<nums.size();i++) {
        set<int> temp_s;
        for(auto it=s.begin();it!=s.end();it++) {
            if(target == *it+nums[i])
                return true;
            temp_s.insert(*it+nums[i]);
        }

        s.insert(temp_s.begin(), temp_s.end());
    }

    return false;
}

int main() {

    // cout << longest_substring_without_repeating_characters("") << endl;

    // auto v = vector<int>{3, 4, 5, 6};
    // auto ans = searchRange(v, 3);

    cout << canPartition(vector<int>{1,5,11,5}) << endl;

}


