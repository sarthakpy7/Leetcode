class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        int n = as.size();
        vector<int> st;

        for (int i = 0; i < n; i++) {
            if (as[i] > 0) {
                st.push_back(as[i]);
            }

            else {
                while (!st.empty() && st.back() > 0 && abs(as[i]) > st.back()) {
                    st.pop_back();
                }
                if (!st.empty() && st.back() == abs(as[i])) {
                    st.pop_back();
                } else if (st.empty() || st.back() < 0) {
                    st.push_back(as[i]);
                }
            }
        }
        return st;
    }
};