class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long res = 0;
        for (int left = 0, right = 0, n = nums.size(); right < n; ++right) {
            k -= freq[nums[right]]++;
            while (k <= 0) {
                res += n - right;
                k += --freq[nums[left++]];
            }
        }
        return res;
    }
};