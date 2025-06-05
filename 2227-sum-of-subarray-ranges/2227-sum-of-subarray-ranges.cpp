class Solution {
public:
  vector<int> NSE(vector<int>& nums , int n){
    stack<int> st;
    vector<int> nse(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        nse[i]=st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
  } 
  vector<int> PGEE(vector<int>& nums , int n){
    stack<int> st;
    vector<int> pgee(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]<=nums[i]){
            st.pop();
        }
        pgee[i]=st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pgee;
  } 
  vector<int> PSEE(vector<int>& nums , int n){
    stack<int> st;
    vector<int> psee(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }
        psee[i]=st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
  }
  vector<int> NGE(vector<int>& nums , int n){
    stack<int> st;
    vector<int> nge(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]<nums[i]){
            st.pop();
        }
        nge[i]=st.empty() ? n : st.top();
        st.push(i);
    }
    return nge;
  }
    long long sumMax(vector<int>& nums) {
        int n = nums.size();
        long long total1 = 0;

        vector<int> nge = NGE(nums , n);
        vector<int> pgee = PGEE(nums , n);

        for (int i = 0; i < n; i++) {
            long long r =nge[i] - i;
            long long l = i - pgee[i];
            total1 = (total1 + (l * r* nums[i]));
        }
        return total1;
    }
   long long sumMin(vector<int>& nums) {
        int n = nums.size();
        long long total2 = 0;

        vector<int> nse = NSE(nums , n);
        vector<int> psee=PSEE(nums , n);

        for (int i = 0; i < n; i++) {
            long long r =nse[i] - i;
            long long l = i - psee[i];
            total2 = (total2 + (l * r* nums[i]));
        }
        return total2;
    }
  
    long long subArrayRanges(vector<int>& nums) {
        return (sumMax(nums) - sumMin(nums));
    }
};