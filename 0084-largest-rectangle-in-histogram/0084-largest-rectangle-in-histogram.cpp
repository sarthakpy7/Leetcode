class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxa = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();  // ✅ Fix: pop the element after using it
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxa = max(heights[element] * (nse - pse - 1), maxa);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxa = max(maxa, heights[element] * (nse - pse - 1));
        }

        return maxa;
    }
};
