class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size();
        int n = num2.size();

        vector<int> num (n + m, 0);

        for (int i = m-1; i >=0; i--){
            for (int j = n-1; j >=0; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + num[i + j + 1];
                num[i + j + 1] = sum%10;
                num[i+j] += sum/10;
            }
            
        }

        int idx = 0;
            string res = "";
            while(idx < num.size() && num[idx] == 0) idx++;
            for (; idx < num.size(); idx++){
                res += (num[idx] + '0');
            }
            return res;
    }
};