#include <vector>
#include <iostream>

using namespace std;

int solve(vector<int> &A, int B) {
    int count=0;
    bool isOneFound;
    
    for(int i=0;i<A.size();i++) {
        int j=(i+B-1);
        isOneFound = false;
        for(; j>=(i-B+1); j--) {
            if(j>=0 && j<A.size()) {
                if(A[j]==1) {
                    isOneFound=true;
                    count++;
                    i=j+B;
                    break;
                }
            }
        }
        
        if(!isOneFound) return -1;
    }
    
    return count;
}


// 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0
// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
int main() {
    // vector<int> A{0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0};
    // int B=12;

    vector<int> A{1,1,1,1,1};
    int B=3;

    cout << solve(A, B) << endl;

    return 0;
}