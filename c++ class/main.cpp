#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>

using namespace std;

// class Mashroor {
//     private: 
//     string s;

//     public:
//     void set(string s) {
//         this->s = s;
//     }

//     void print() {
//         cout << s << endl;
//     }
// };

int main() {
    cout << "Hello world !!!" << endl;

    // Mashroor *m = new Mashroor();
    // m->set("abc");
    // m->print();

    // vector<int> v;

    // for(int i=1;i<=5;i++)
    // {
    //     v.push_back(i);
    // }

    // // int a = 
    // // v.pop_back();
    // cout << endl;

    // cout << v.size() << endl;
    // cout << v.capacity() << endl;

    // cout << endl;
    // auto r = v.begin();

    // for(int i=0;i<v.size();i++) {
    //     // auto a = v[i];
    //     cout << *r++ << endl;
    //     // r--;
    // }

    // queue<int> q;

    // for(int i=1;i<=5;i++)
    // {
    //     q.push(i);
    // }

    // cout << q.size() << endl;

    // for(;!q.empty();) {
        
    //     cout << q.size() << " - " << q.front() << endl;
    //     q.pop();
    // }

    // stack<int> s;

    // for(int i=1;i<=5;i++)
    // {
    //     s.push(i);
    // }

    // for(;!s.empty();) {   
    //     cout << s.size() << " - " << s.top() << endl;
    //     s.pop();
    // }

    // unordered_map<int, int> m;

    // m[1] = 11;
    // m[22] = 22;
    // m[99] = 99;
    // m[4] = 44;
    // m[7] = 77;

    // for(auto it=m.begin();it!=m.end();it++) {
    //     cout << it->first << " " << it->second << endl;
    // }

    set<int> s;

    auto i = s.insert(10);
    cout << i.second << endl;

    i = s.insert(9);
    cout << i.second << endl;

    i = s.insert(4);
    cout << i.second << endl;

    for(auto it=s.begin();it!=s.end();it++) {
        cout << *it << endl;
    }

    return 0;
}