class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
      set<int>s(nums.begin(),nums.end());  
      int count=1;
      int ans=INT_MIN;
      int prev=INT_MIN;
     for (auto i : s) {
        if(i == prev + 1){
           count++;
        }else{
            ans=max(ans,count);
            count=1;
        }
        prev=i;
      }
       ans = max(ans, count);
      return ans;
    }
};