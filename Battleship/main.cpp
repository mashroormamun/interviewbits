#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

double getHitProbability(int R, int C, vector<vector<int>> G) {
  int hit = 0;
  
  for(int c=0;c<C;c++) {
    for (int r=0;r<R;r++) {
      if(G[r][c] != 0) hit++;
    }
  }
  
  double probability = (double)hit / double(R*C);
  
  return probability;
}

int main() {
    vector<vector<int>> G = {
        {0,0,1},
        {1,0,1}
    };

    cout << getHitProbability(2,3,G) << endl;

    return 0;
}