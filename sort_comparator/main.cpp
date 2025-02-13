// A C++ program to demonstrate
// STL sort() using
// our own comparator
#include <bits/stdc++.h>
using namespace std;

bool compareInterval(int i1, int i2)
{
    return (abs(i1) < abs(i2));
}
  
int main()
{
    vector<int> v = {-4,-1,0,3,10};
    
    sort(v.begin(), v.end(), compareInterval);
  
    cout << "sorted: \n";
    for (auto it = v.begin(); it != v.end() ; it++) {
        cout << "[" << *it << "] ";
    }
  
    return 0;
}