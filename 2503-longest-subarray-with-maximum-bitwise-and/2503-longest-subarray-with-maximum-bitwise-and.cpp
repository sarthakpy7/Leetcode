class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Note
        // The first one we need to find the subarray that is having the maximum value of the Bitwise AND.
        // If the max Bitwise AND that could be found from the given vector is k for example then we need to consider only the subarrays with the AND value to be k.
        // 1 2 3 3 2 2
        // Even if we consider single element then also it is the sub array
        // 1 2 3 3 2 2
        // 1 2 3 4
        // 4
        // 1 2 9 9 2 3 9 9 9 8 5
        // 9 & 9 --> 9
        // 9 & 3 --> 1001 & 0011 --> 1
        int maxNumber = INT_MIN;
        for(auto &ele : nums) maxNumber = max(maxNumber, ele);
        int cnt = 0;
        int ans = 0;
        for(auto &ele : nums){
            if(ele == maxNumber) cnt += 1;
            else cnt = 0;
            ans = max(ans, cnt);
        }
        return ans;
    }
};