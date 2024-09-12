#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;
    int frontt;

public:
    MyQueue() {
        frontt = -1; 
    }
    
    void push(int x) {
        if (s1.empty()) {
            frontt = x; 
        }
        s1.push(x); 
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop(); 
        return res;
    }
    
    int peek() {
        if (!s2.empty()) {
            return s2.top(); 
        }
        return frontt; 
    }
    
    bool empty() {
        return s1.empty() && s2.empty(); 
    }
};


