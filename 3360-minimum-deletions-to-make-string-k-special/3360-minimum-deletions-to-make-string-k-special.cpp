class Solution {
public:
    int minimumDeletions(string w, int k) {
        int n = w.length(); 
        map<char, int> frq; 
        for(auto &i : w)frq[i]++; 
        vector<int>rep; 
        for(auto [a,b]:frq)rep.push_back(b); 
        sort(rep.begin(), rep.end());
        int sz = rep.size(); 
        vector<int>suf(sz); 
        suf[sz-1] = rep[sz-1];
        for(int i = sz - 2; i>=0;--i)suf[i] = suf[i+1] + rep[i];
        for(auto i:rep)cout<<i<<' '; 
        cout<<endl;
        for(auto i:suf)cout<<i<<' '; 
        int ans = INT_MAX; 
        for(int i = 0; i<sz;++i){
            int tar = rep[i] + k; 
            auto it = upper_bound(rep.begin()+i,rep.end(),tar);
            int semi{}; 
            if(i>0)semi+=(suf[0]-suf[i]);
            if(it!=rep.end()){
                int idx = it - rep.begin(); 
                int tmp = suf[idx]; 
                tmp -= (tar * (sz - idx)); 
                semi += tmp; 
            }
            ans = min(ans, semi); 
        }
        return ans; 
    }
};