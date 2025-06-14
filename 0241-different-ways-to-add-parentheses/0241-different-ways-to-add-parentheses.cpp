class Solution {
public:
    int n = 0;
    vector<vector<vector<int>>> dp;
    vector<int> solve(string& expression, int i, int j) {
        if(!dp[i][j].empty()) return dp[i][j];
        vector<int> results;
        bool isNumber = true;
        for (int k = i; k <= j; ++k) {
            if (!isdigit(expression[k])) {
                isNumber = false;
                break;
            }
        }

        if (isNumber) {
            results.push_back(stoi(expression.substr(i, j - i + 1)));
            return results;
        }
        for (int k = i; k <= j; k++) {
            if (isdigit(expression[k]))
                continue;

            vector<int> left = solve(expression, i, k - 1);
            vector<int> right = solve(expression, k + 1, j);
            char op = expression[k];

            for (auto l : left) {
                for (auto r : right) {
                    int ans = 0;
                    if (op == '-')
                        ans = l - r;
                    else if (op == '+')
                        ans = l + r;
                    else if (op == '*')
                        ans = l * r;
                    results.push_back(ans);
                }
            }
        }
        return dp[i][j] = results;
    }
    vector<int> diffWaysToCompute(string expression) {
        n = expression.length();
        dp.assign(n, vector<vector<int>>(n));
        return solve(expression, 0, n - 1);
    }
};