class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count=0;
        long long prefixSum = 0;
        int s=0;
        

        for(int i=0;i<nums.size();i++){
            
            
            prefixSum = prefixSum + nums[i];
           

            while(s<=i &&  prefixSum*(i-s+1)>=k){
                prefixSum = prefixSum - nums[s];
                
                s++;
            }
            count = count + i-s+1;

        }
        return count;


        
    }
};