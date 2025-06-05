class Solution {
public:
    typedef unsigned long long ll;
     vector<int> findnse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

     vector<int> findpsee(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;
        for (int i = 0; i <n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }


    int sumSubarrayMins(vector<int>& arr) {
        const int mod = 1e9 + 7;

        int n = arr.size();
        vector<int> nse = findnse(arr);
        vector<int> psee = findpsee(arr);

        ll total = 0;
        for (int i = 0; i < n; i++) {
            ll left = i - psee[i];
            ll right = nse[i] - i;
            total = (total + ((left * right * arr[i]) % mod)) % mod;
        }
        return total;
    }
};