class Solution {
public:
    bool isValid(string s) {
        map<char, int> mp;
        mp['('] = 1;
        mp['{'] = 2;
        mp['['] = 3;
        mp[')'] = -1;
        mp['}'] = -2;
        mp[']'] = -3;

        stack<int> st;
        int is_balanced = 1;

        for (auto v : s) {
            int val = mp[v];
            if (val > 0) {
                st.push(val);
            } else {
                if (!st.empty() && st.top() + val == 0) {
                    st.pop();
                } else {
                    is_balanced = 0;
                    break;
                }
            }
        }

        if (!st.empty()) {
            is_balanced = 0;
        }

        return is_balanced == 1;
    }
};
