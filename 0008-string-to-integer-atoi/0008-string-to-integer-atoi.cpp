class Solution {
public:
    int myAtoi(string s) {
        int ind = 0;
        while (ind < s.size() && s[ind] == ' ') ind++;

        bool flag = true;
        if (ind < s.size() && s[ind] == '-') {
            flag = false;
            ind++;
        } else if (ind < s.size() && s[ind] == '+') {
            ind++;
        }

        while (ind < s.size() && s[ind] == '0') ind++;

        int start = ind;
        while (ind < s.size() && s[ind] >= '0' && s[ind] <= '9') ind++;

        if (start == ind) return 0;

        long long ans = 0;
        for (int i = start; i < ind; i++) {
            int digit = s[i] - '0';
            ans = ans * 10 + digit;
            
            if (flag && ans > INT_MAX) return INT_MAX;
            if (!flag && -ans < INT_MIN) return INT_MIN;
        }

        if (!flag) ans = -ans;

        return (int)ans;
    }
};