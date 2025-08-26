#include <vector>
#include <unordered_map>

class Solution {
public:
    bool partitionArray(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) {
            return false;
        }

        int num_groups = n / k;
        std::unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        for (auto const& pair : freq) {
            if (pair.second > num_groups) {
                return false;
            }
        }

        return true;
    }
};