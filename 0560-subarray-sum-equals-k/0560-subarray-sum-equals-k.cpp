class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(i>0)nums[i] += nums[i-1];
        }
        int sum =0;
        map<int,int> mp;
        mp[0]++;
        for(int i=0;i<nums.size();i++){
            sum+= mp[nums[i]-k];
            mp[nums[i]]++;
        }
        return sum;
    }
     
};