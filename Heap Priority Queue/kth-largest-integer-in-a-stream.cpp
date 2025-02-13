#include <iostream>
#include <queue>

using namespace std;

void maxheap() {
    // Max heap (default for std::priority_queue)
    std::priority_queue<int> maxHeap;

    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(9);
    maxHeap.push(1);

    while(!maxHeap.empty()) {
        cout << maxHeap.top() << endl;
        maxHeap.pop();
    }
}

void minHeap(){
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(9);
    minHeap.push(1);

    while(!minHeap.empty()) {
        cout << minHeap.top() << endl;
        minHeap.pop();
    }
}


class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(int i=0;i<nums.size();i++) {
            minHeap.push(nums[i]);
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};


// int main() {
//     maxheap();
//     // minHeap();
//     // vector<int>v{1, 2, 3, 3};

//     // KthLargest kthLargest(3, v);
//     // cout << kthLargest.add(3) << endl;   // return 3
//     // cout << kthLargest.add(5) << endl;   // return 3
//     // cout << kthLargest.add(6) << endl;   // return 3
//     // cout << kthLargest.add(7) << endl;   // return 5
//     // cout << kthLargest.add(8) << endl;   // return 6
    
//     return 0;
// }

// Define a Task structure
struct Task {
    int priority;
    std::string name;

    Task(int p, string n) : priority(p), name(n){}
    
};

struct ComparePriority {
    // Comparison operator for max heap (higher priority comes first)
    bool operator()(const Task& a, const Task& b) const {
        return a.priority > b.priority;
    }
};


int main() {
    // Max heap for Task (higher priority first)
    std::priority_queue<Task> maxHeap;

    // Min heap for Task (lower priority first)
    std::priority_queue<Task, std::vector<Task>, ComparePriority> minHeap;

    // Add tasks to the max heap
    minHeap.push(Task(3, "Task 1"));
    // maxHeap.push(Task(1, "Task 2"));
    // maxHeap.push(Task(4, "Task 3"));
    // maxHeap.push(Task(2, "Task 4"));

    // std::cout << "Max Heap tasks (higher priority first):\n";
    // while (!maxHeap.empty()) {
    //     Task task = maxHeap.top();
    //     std::cout << "Priority: " << task.priority << ", Name: " << task.name << '\n';
    //     maxHeap.pop();
    // }

    // // Add tasks to the min heap
    minHeap.push({3, "Task 1"});
    minHeap.push({1, "Task 2"});
    minHeap.push({4, "Task 3"});
    minHeap.push({2, "Task 4"});

    std::cout << "\nMin Heap tasks (lower priority first):\n";
    while (!minHeap.empty()) {
        Task task = minHeap.top();
        std::cout << "Priority: " << task.priority << ", Name: " << task.name << '\n';
        minHeap.pop();
    }

    return 0;
}
