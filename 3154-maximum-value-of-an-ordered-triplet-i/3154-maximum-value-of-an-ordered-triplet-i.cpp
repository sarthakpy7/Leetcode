class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int maxI= nums[0];
        int maxDiff = 0;
        long long maxAns = 0;

        for(int j = 1; j<n; j++){
            // We will multiply our maxDiff so far with nums[j] as k
            maxAns = max(maxAns, 1LL*maxDiff*nums[j]);

            // Now we need to update the maxDiff with maximum value
            maxDiff = max(maxDiff, maxI - nums[j]);

            // To update the maxDiff we also need to update the maxI
            maxI = max(maxI, nums[j]);
        }
        return maxAns;
    }
};