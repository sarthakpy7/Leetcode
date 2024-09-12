#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;
    int frontt;

public:
    MyQueue() : frontt(-1) {} 
    
    void push(int x) {
        if (s1.empty()) frontt = x;
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int result = s2.top();
        s2.pop();
        return result;
    }
    
    int peek() {
        return s2.empty() ? frontt : s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
