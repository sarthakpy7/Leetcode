class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);
        int r = 0, l = 0, cnt = 0, minlen = INT_MAX, sindex = -1;
        int n = s.size();
        
        // Build frequency map for t
        for (int i = 0; i < t.size(); i++) hash[t[i]]++;
        
        while (r < n) {
            if (hash[s[r]] > 0) cnt++;   // valid char found
            hash[s[r]]--;                // decrease freq
            
            // When all chars are matched
            while (cnt == t.size()) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sindex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt--; // losing a required char
                l++;
            }
            r++;
        }
        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};