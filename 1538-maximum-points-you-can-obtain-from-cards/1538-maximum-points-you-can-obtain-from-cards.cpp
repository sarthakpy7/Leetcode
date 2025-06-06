class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        int lsum=0;
        int rsum=0;
        int maxsum=0;
        for (int i=0;i<k;i++){
            lsum=lsum+arr[i];
            maxsum = lsum;
        }
        int rind = n-1;
        
        for(int i=k-1;i>=0;i--){
            lsum = lsum - arr[i];
            rsum = rsum + arr[rind];
            maxsum = max (maxsum , lsum + rsum);
            rind --;
        }
        return maxsum;
    }
};