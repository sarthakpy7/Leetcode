class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return n;

        sort(nums.begin(), nums.end());

        int count = 1;
        int start = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] - start > k) {
                ++count;
                start = nums[i];
            }
        }
        return count;
    }
};