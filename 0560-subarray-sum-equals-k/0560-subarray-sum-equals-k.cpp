class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        map<int, int> mp;
        mp[0] = 1;

        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }
            mp[prefixSum]++;
        }

        return count;
    }
};
