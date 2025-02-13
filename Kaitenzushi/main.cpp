#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// Write any include statements here

int getMaximumEatenDishCount(int N, vector<int> D, int K) {
  vector<int> buffer;
  unordered_map<int, bool> m;

  int buffer_index = 0;

  int result = 0;

  for (int i=0;i<D.size(); i++) {
    //auto it = find(buffer.begin(), buffer.end(), D[i]);
    //if(it == buffer.end()) {
    
    if(m.count(D[i]) == 0) {
        result++;
        if(buffer.size()<K) {
            buffer.push_back(D[i]);
            m[D[i]] = true;
        } else {
            int to_remove = buffer[(buffer_index++)%K];
            m.erase(to_remove);

            buffer[(buffer_index++)%K] = D[i];
            m[D[i]] = true;
        }
    }
  }
  
  return result;
}

int main() {

    int N=7;
    vector<int> D {1, 1, 1, 1, 1, 1, 1};
    int K=0;
    cout << getMaximumEatenDishCount(N, D, K) << endl;
    return 0;
}