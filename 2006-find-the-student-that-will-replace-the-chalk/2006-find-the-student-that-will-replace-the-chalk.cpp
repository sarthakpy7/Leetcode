class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int initialChalkPieces) {
        long long T = 0;
        for (int use : chalk) {
            T += use;
        }
        
        int remaining = initialChalkPieces % T;
        
        for (int n = 0; n < chalk.size(); n++) {
            if (remaining < chalk[n]) {
                return n;
            }
            remaining -= chalk[n];
        }
        
        return 0;
    }
};

static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
