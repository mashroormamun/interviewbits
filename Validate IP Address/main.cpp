#include<unordered_map>
#include<vector>
#include<iostream>

using namespace std;

#define ipv4 1
#define ipv6 2
#define none 3

class Solution {
public:
    bool is_valid_hex(char c) {
        switch(c){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
                return true;
        }
        
        return false;
    }
    
    int checkip(string queryIP) {
        if(queryIP.length() <=5 ) return none;
        
        for(int i=0;i<5;i++) {
            if(queryIP[i]==':') return ipv6;
            
            if(queryIP[i]=='.') return ipv4;
        }
        
        return none;
    }
    
    string validIPAddress(string queryIP) {
        auto check = checkip(queryIP);

        if(check==none) return "Neither";
        
        if(check==ipv4) {
            if(queryIP[0]=='.' || queryIP[queryIP.length()-1]=='.') return "Neither";
            int dot_count = 0;
            int left=0, right=0;
            
            for(int i=0;i<queryIP.length();i++) {

                if(queryIP[i]=='.' || i==(queryIP.length()-1)) {
                    if(queryIP[i]=='.') {
                        dot_count++;
                        right=i-1;
                    } else {
                        right=i;
                    }
                    
                    if(left>right) return "Neither";
                    
                    if(right-left+1 == 1) {
                        if(queryIP[left]<'0' || queryIP[left]>'9') return "Neither";
                    }
                    
                    if(right-left+1 == 2) {
                        if(queryIP[left]<'1' || queryIP[left]>'9') return "Neither";
                        if(queryIP[right]<'0' || queryIP[right]>'9') return "Neither";
                    }

                    if(right-left+1 == 3) {
                        if(queryIP[left]<'1' || queryIP[left]>'2') return "Neither";

                        if(queryIP[right]<'0' || queryIP[right]>'9') return "Neither";
                        
                        if(queryIP[left]=='1') {
                            if(queryIP[left+1]<'0' || queryIP[left+1]>'9') return "Neither";
                        }
                        
                        if(queryIP[left]=='2') {
                            if(queryIP[left+1]<'0' || queryIP[left+1]>'5') return "Neither";

                            if(queryIP[left+1]=='5') {
                                if(queryIP[right]<'0' || queryIP[right]>'5') return "Neither";
                            }
                        }
                    }

                    if(right-left+1 > 3) {
                        return "Neither";
                    }
                    
                    left=i+1;    
                } 

                
            }
            
            if(dot_count!=3) return "Neither";
            
            return "IPv4";
        }
        
        int colon_count = 0;
        int char_count = 0;
        
        for(int i=0;i<queryIP.length();i++) {
            
            if(queryIP[i]==':') {
                if(char_count==0) return "Neither";
                char_count=0;
                colon_count++;
            } else {
                if(!is_valid_hex(queryIP[i])) return "Neither";
                char_count++;
            }

            if(char_count>=5) return "Neither";
            
        }
        
        if(colon_count!=7) return "Neither";
        
        return "IPv6";
    }
};


int main() {
    Solution s;
    cout << s.validIPAddress("6284.56.78.9") << endl;

    return 0;
}