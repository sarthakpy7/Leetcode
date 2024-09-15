/*
By  :-: savetrees
Used:-: Bitmasking
*/
class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> m(32, -2);
        m[0] = -1;
        int maxLen = 0, mask = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            mask ^= (c == 'a') ? 1 : 0;
            mask ^= (c == 'e') ? 2 : 0;
            mask ^= (c == 'i') ? 4 : 0;
            mask ^= (c == 'o') ? 8 : 0;
            mask ^= (c == 'u') ? 16 : 0;
            int p = m[mask];
            m[mask]=(p==-2) ? i : m[mask];
            maxLen=(p==-2) ? maxLen : max(maxLen, i - p);}
        return maxLen;}};