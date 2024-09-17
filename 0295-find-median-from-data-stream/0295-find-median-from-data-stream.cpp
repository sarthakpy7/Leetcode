#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    multiset<int> low, high;  
    MedianFinder() {
    }
    void addNum(int num) {
        if (low.empty() || num <= *low.rbegin()) {
            low.insert(num);
        } else {
            high.insert(num);
        }
        balance();
    }
    void balance() {
        if (low.size() < high.size()) {
            int x = *high.begin();
            high.erase(high.find(x));
            low.insert(x);
        }
        if (low.size() > high.size() + 1) {
            int x = *low.rbegin();
            low.erase(low.find(x));
            high.insert(x);
        }
    }
    double findMedian() {
        if ((low.size() + high.size()) % 2 == 1) {
            return *low.rbegin();  
        } else {
            return (*low.rbegin() + *high.begin()) / 2.0;  
        }
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */