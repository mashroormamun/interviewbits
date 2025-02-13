#include <iostream>
#include <stack>

using namespace std;

class MinStack {

struct v {
    int value;
    int min;
};

stack<v> *s;
int min = INT32_MAX;

public:
    MinStack() {
        s = new stack<v>();
    }
    
    void push(int val) {
        if(val<min) {
            min = val;
        }

        s->push(v{val, min});
    }
    
    void pop() {
        s->pop();

        if(s->empty()) {
            min = INT32_MAX;
        } else {
            auto p = s->top();
            min = p.min;
        }
    }
    
    int top() {
        auto p = s->top();
        return p.value;
    }
    
    int getMin() {
        return min;
    }
};


int main() {

    MinStack minStack;
    minStack.push(10);
    minStack.pop();
    minStack.push(20);
    cout << minStack.top() << endl;    // return 2
    minStack.push(-20);
    cout << minStack.getMin() << endl; // return 0
    
    return 0;
}