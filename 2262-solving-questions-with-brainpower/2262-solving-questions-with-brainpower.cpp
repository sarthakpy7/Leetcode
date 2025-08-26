class Solution {
public:
    long long dp[100001];
    long long solve(vector<vector<int>>& nums,int index){
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1){
            return dp[index];
        }
         long long c1=0,c2=0;
         c1=nums[index][0]+solve(nums,index+nums[index][1]+1);
         c2=solve(nums,index+1);
          return dp[index]= max(c1,c2);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return solve(questions,0);
        
    }
};