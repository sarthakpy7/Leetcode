#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> inc(n, 1); // inc[i] stores length of the longest increasing subarray ending at i
        
        // Fill the inc array
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                inc[i] = inc[i - 1] + 1;
            }
        }
        
        // Binary search for the maximum k
        int left = 1, right = n / 2, maxK = 0;
        
        while (left <= right) {
            int k = left + (right - left) / 2;
            bool found = false;
            
            // Check for two adjacent subarrays of length k
            for (int i = k; i < n; ++i) {
                if (inc[i] >= k && inc[i - k] >= k) {
                    found = true;
                    break;
                }
            }
            
            if (found) {
                maxK = k;  // Update maxK if we found valid k
                left = k + 1;
            } else {
                right = k - 1;
            }
        }
        
        return maxK;
    }
};
