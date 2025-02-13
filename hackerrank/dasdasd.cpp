#include <bits/stdc++.h>

using namespace std;

void bigIntSum(string &a, char b) {
    // cout << a << " " << b << endl;

    // reverse(a.begin(), a.end());
    int carry = 0;
    
    for(int i=0; i<a.length(); i++) {
        

        int sum = a[i] - '0' + carry;
        if(i==0) sum += b - '0';
            
        if(sum>=10) carry = 1;
        else carry = 0;
        
        a[i] = (sum % 10) + '0';
    }

    if(carry == 1) {
        a.append("1");
    }
    
    // reverse(a.begin(), a.end());
}

int superDigit(string n, int k) {
    string sum = "0";

    reverse(n.begin(), n.end());
    
    for(int i=0; i<k; i++) {
        for(int j=0; j<n.length(); j++) {
            bigIntSum(sum, n[j]);
        }
    }

    cout << sum << endl;
    
    n = sum;
    
    for(;sum.length()!=1;) {
        sum = "0";
        for(int i=0; i<n.length(); i++) {
            bigIntSum(sum, n[i]);
        }   

        n = sum;
        cout << sum << endl;

    }

    


    return sum[0]-'0';
}

int main() {
    superDigit("9875", 4);

    return 0;
}