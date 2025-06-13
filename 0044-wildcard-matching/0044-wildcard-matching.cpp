class Solution {
public:
    // Tabulation - 
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        // base case - 
        dp[0][0] =  true;
        for(int i=1; i<=n; i++) dp[i][0] = false;
        // Base case: empty string, non-empty pattern
        for(int j=1; j<=m; j++){
            bool flag = true;
            for(int x=1; x<=j; x++){
                if(p[x-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*') {
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};