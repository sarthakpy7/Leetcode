class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int stringLength = s.size();
        if (stringLength % k) {
            for (int i = 0; i < k - (stringLength % k); ++i) {
                s.push_back(fill);
            }
        }
        vector<string> substrings;
        for (int i = 0; i < s.size() / k; ++i) {
            substrings.push_back(s.substr(i * k, k));
        }
        return substrings;
    }
};