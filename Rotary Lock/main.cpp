#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
  long long time = 0,a,b;
  
  for(int i=0; i<C.size(); i++) {
    if(i==0) {
      a = 1 - C[i];
      b = C[i] - 1;
    } else {
      a = C[i-1] - C[i];
      b = C[i] - C[i-1];
    }
    
    a = a<0 ? a+N:a;
    b = b<0 ? b+N:b;
    
    int m = min (a,b);
    
    time += m;
  }
  
  return time;
}




