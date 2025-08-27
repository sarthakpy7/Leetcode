class Solution {
    using ll = long long;
    string suffix;
    int limit;
    ll dp[20][2]; // dp[pos][tight]

    ll countValid(const string &numStr) {
        int n = numStr.size();
        int suffixStart = n - suffix.size();
        memset(dp, -1, sizeof(dp));

        function<ll(int, bool)> dfs = [&](int pos, bool tight) -> ll {
            if (pos == n) return 1;
            if (dp[pos][tight] != -1) return dp[pos][tight];

            ll res = 0;
            int maxDigit = tight ? numStr[pos] - '0' : 9;

            if (pos >= suffixStart) {
                int idx = pos - suffixStart;
                int digit = suffix[idx] - '0';
                if (digit <= maxDigit && digit <= limit) {
                    bool nextTight = tight && (digit == maxDigit);
                    res += dfs(pos + 1, nextTight);
                }
            } else {
                for (int d = 0; d <= min(maxDigit, limit); ++d) {
                    bool nextTight = tight && (d == maxDigit);
                    res += dfs(pos + 1, nextTight);
                }
            }

            return dp[pos][tight] = res;
        };

        return dfs(0, true);
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, const string &s) {
        this->limit = limit;
        this->suffix = s;

        ll suffixNum = stoll(s);
        if (finish < suffixNum) return 0;

        ll countToFinish = countValid(to_string(finish));
        ll countToStart = (start > suffixNum) ? countValid(to_string(start - 1)) : 0;

        return countToFinish - countToStart;
    }
};