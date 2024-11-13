#include <vector>
#include <algorithm>

class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        long long fairPairsCount = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int left = i + 1;
            int j = std::lower_bound(nums.begin() + left, nums.end(), lower - nums[i]) - nums.begin();
            int k = std::upper_bound(nums.begin() + left, nums.end(), upper - nums[i]) - nums.begin();
            fairPairsCount += (k - j);
        }
        
        return fairPairsCount;
    }
};
