#include<iostream>
#include<string>
#include<vector>

using namespace std;

int binary_search(vector<int> v, int target) {
    int start=0, end=v.size()-1;

    while(start<end) {
        int mid = start + (end-start)/2;
        
        if(v[mid] == target) return mid;

        if(v[mid]>target) {
            end=mid-1;
        }else {
            start=mid+1;
        }
    }

    return -1;
}

int binary_search(vector<int> &v, int start, int end, int target) {
    cout << start << " "<< end << " " << target << endl;
    
    while(start<=end) {
        int mid = start + (end-start)/2;

        cout << mid << endl;
        
        if(v[mid] == target) return mid;

        if(v[mid]>target) {
            end=mid-1;
        }else {
            start=mid+1;
        }
    }

    return -1;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    for(int i=0; i<numbers.size(); i++) {
        int other_number = target-numbers[i];

        int other_number_index = binary_search(numbers, i+1, numbers.size()-1, other_number);

        if(other_number_index !=-1) {
            return vector<int> {i+1, other_number_index+1};
        }
    }

    return vector<int> {-1, -1};
}

bool is_vowel(char c) {
    if(c=='a'
    || c=='e'
    || c=='i'
    || c=='o'
    || c=='u'
    || c=='A'
    || c=='E'
    || c=='I'
    || c=='O'
    || c=='U')
    return true;

    return false;
}

void reverse_vowel(string &s) {
    int left = 0;
    int right = s.length();

    while(left < right) {
        while(!is_vowel(s[left])) {
            left++;
        }

        while(!is_vowel(s[right])) {
            right--;
        }

        if(left>=right) break;

        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int rotate_binary_search(vector<int> &v, int start, int end, int target) {
    int rotate=4;
    
    while(start<=end) {
        int mid = start + (end-start)/2;
        int rotated_mid= (mid+rotate)%v.size();

        if(v[rotated_mid] == target) return rotated_mid;

        if(v[rotated_mid]>target) {
            end=mid-1;
        }else {
            start=mid+1;
        }
    }

    return -1;
}

int main() {
   
    // vector<int> numbers{2,7,11,15};
    // auto ans = twoSum(numbers, 9);

    // cout << ans[0] << " " << ans[1] << endl;

    // string s = "leetcode";
    // reverse_vowel(s);

    // cout << s << endl;


    vector<int> numbers{4,5,6,7,1,2,3};

    auto index = rotate_binary_search(numbers, 0, numbers.size()-1, 1);
    cout << index << endl;

    return 0;
}