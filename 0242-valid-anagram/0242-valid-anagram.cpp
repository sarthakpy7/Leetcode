class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp_s,mp_t;
        
        for (auto j:s){
            mp_s[j]++;
        }
        for(auto j:t){
            mp_t[j]++;
        }        
        if(mp_s == mp_t){
            return true;
        }
        return false;
    }
};