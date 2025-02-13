#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

// long long nearestSmallUniformNumber(long long A) {
//     long long copyA = A;
//     int len = 0;
//     long long lastDigit = copyA;
    
//     while(copyA != 0) {
//         lastDigit = copyA;
//         copyA /= 10;
//         len++;
//     }

//     if (len == 1) return A;

//     long long newUniformNumberLarge = 0;
//     long long newUniformNumberSmall = 0;
//     long long newUniformNumberPrev = 0;

//     for (int i=0;i<len;i++) {
//         newUniformNumberLarge = 10 * (newUniformNumberLarge) + lastDigit;
//         newUniformNumberSmall = 10 * (newUniformNumberSmall) + (lastDigit-1);
//         newUniformNumberPrev = 10 * (newUniformNumberPrev) + 9;
//     }

//     newUniformNumberPrev /= 10;

//     if (newUniformNumberLarge <= A) return newUniformNumberLarge;
//     if (newUniformNumberSmall!=0 && newUniformNumberSmall <= A) return newUniformNumberSmall;
//     if (newUniformNumberPrev <= A) return newUniformNumberPrev;

//     return 0;
// } 

// long long nearestLargeUniformNumber(long long A) {
//     long long copyA = A;
//     int len = 0;
//     long long lastDigit = copyA;
    
//     while(copyA != 0) {
//         lastDigit = copyA;
//         copyA /= 10;
//         len++;
//     }

//     if (len == 1) return A;

//     long long newUniformNumberSmall = 0;
//     long long newUniformNumberLarge = 0;
//     long long newUniformNumberNext = 0;

//     for (int i=0;i<len;i++) {
//         newUniformNumberSmall = 10 * (newUniformNumberSmall) + lastDigit;
//         newUniformNumberLarge = 10 * (newUniformNumberLarge) + (lastDigit+1);
//         newUniformNumberNext = 10 * (newUniformNumberNext) + 9;
//     }

//     if (newUniformNumberSmall >= A) return newUniformNumberSmall;
//     if (newUniformNumberLarge >= A) return newUniformNumberLarge;
//     if (newUniformNumberNext >= A) return newUniformNumberNext;

//     return 0;

// }

// int getUniformIntegerCountInInterval(long long A, long long B) {
//   long long newA = nearestLargeUniformNumber(A);
//   long long newB = nearestSmallUniformNumber(B);

// //   cout << newA << " " << newB << endl;

//   int digitA = A%10;
//   int digitB = B%10;

//   int count = (9-digitA+1) + digitB + (digitLen(B)-digitLen(A)-1)*9;

//   return count;
// }

int digitLen(long long A) {
    int len = 0;

    while(A != 0) {
        A /= 10;
        len++;
    }

    return len;
}

long long getUniformIntegerCountFromOne(long long A) {
    int len = digitLen(A);

    if(len==1 || len==0) return A;

    long long mask = 1;
    for(int i=0;i<len-1;i++) {
      mask = 10*mask + 1;
    }

    return (len-1)*9 + (A/mask);
}

int getUniformIntegerCountInInterval(long long A, long long B) {
  long long newA = getUniformIntegerCountFromOne(A-1);
  long long newB = getUniformIntegerCountFromOne(B);

  return newB-newA;
}

int main() {
    
    
    
    cout << getUniformIntegerCountInInterval(1, 9) << endl;
    
    return 0;
}