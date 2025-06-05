class Solution {
public:
    vector<int> rspc(const vector<int>& h, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for(int i=n-1; i>=0; i--){
            int curr=h[i];
            while(st.top()!=-1 && h[st.top()]>=curr) st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> lspc(const vector<int>& h, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for(int i=0; i<n; i++){
            int curr=h[i];
            while(st.top()!=-1 && h[st.top()]>=curr) st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangle(const vector<int>& h, int n){
        vector<int> ri(n);
        vector<int> li(n);
        ri = rspc(h, n);
        li = lspc(h, n);
        int maxarea=INT_MIN;
        for(int i=0; i<n; i++){
            int l=h[i];
            if(ri[i]==-1) ri[i]=n;
            int b = ri[i]-li[i]-1;
            int area = l*b;
            maxarea=max(maxarea, area);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m=matrix[0].size();
        vector<int> hist(m, 0);
        int ans =INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1') hist[j]++;
                else hist[j]=0;
            }
            int area = largestRectangle(hist, m);
            ans=max(ans, area);
        }
        return ans;
    }
};