#include <iostream>
#include <vector>

using namespace std;

int perfectPeak(vector<int> &A) {
    vector<int> L(A.size());
    vector<int> R(A.size());

    for (int i=0;i<A.size();i++) {
        if (i==0) {
            L[i] = A[i];
            R[A.size()-1] = A[A.size()-1];
        } else {
            L[i] = max(A[i], L[i-1]);
            R[A.size()-1-i] = min(A[A.size()-1-i], R[A.size()-1-i+1]);
        }
    }

    for (int i=0;i<A.size();i++) {
        cout << L[i] << "\t" ;
    }

    cout << endl;

    for (int i=0;i<A.size();i++) {
        cout << R[i] << "\t" ;
    }    

    cout << endl;

    for (int i=1;i<A.size()-1;i++) {
        // if(A[i] == L[i] && A[i]==R[i]) return 1;
        if(L[i-1] < A[i] && A[i] < R[i+1]) return 1;
    }

    return 0;
}

int main() {
    vector<int> A{5, 1, 4, 3, 6, 8, 10, 7, 9};

    auto ans = perfectPeak(A);

    cout << ans << endl;
}
