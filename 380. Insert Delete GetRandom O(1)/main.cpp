#include <iostream>
using namespace std;

#include <unordered_map>

class RandomizedSet {
public:
    unordered_map<int, bool> *u;

    RandomizedSet() {
        u = new unordered_map<int, bool>();
    }
    
    bool insert(int val) {
        auto success = u->insert({val, true});
        return success.second;
    }
    
    bool remove(int val) {
        auto it = u->find(val);
        if (it != u->end()) {
            u->erase(it);
            return true;
        }

        return false;
    }
    
    int getRandom() {
        auto item = u->begin();
        advance(item, rand()%(u->size()));
        return item->first;
    }
};

int main() {
    unordered_map<int, int> *u = new unordered_map<int, int>();

    auto success = u->insert({23, 1});
    cout << success.second << endl;

    success = u->insert({43, 2});
    cout << success.second << endl;

    success = u->insert({67, 3});
    cout << success.second << endl;

    success = u->insert({43, 2});
    cout << success.second << endl;

    for (auto it=u->begin(); it!=u->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    auto it = u->find(53);
    if(it != u->end()) {
        cout << it->first << " " << it->second << endl;
    } else {
        cout << "not found" << endl;
    }

    // it = u->begin();
    // it=it+2;
    // cout << it->first << " " << it->second << endl;
}