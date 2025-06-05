class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> st;
        for (int i = 0; i < nums.size(); i++) {
            char digit = nums[i];
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        if (st.empty()) return "0";

        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }

        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};