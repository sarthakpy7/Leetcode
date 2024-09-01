class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string ans;
        if ((numerator < 0) ^ (denominator < 0)) {
            ans += "-";
        }
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);

    
        long long integerPart = n / d;
        ans += to_string(integerPart);

        
        long long remainder = n % d;
        if (remainder == 0) return ans;

        ans += ".";

        unordered_map<long long, int> remainderMap;


        while (remainder != 0) {
            if (remainderMap.find(remainder) != remainderMap.end()) {
                ans.insert(remainderMap[remainder], "(");
                ans += ")";
                break;
            }
            remainderMap[remainder] = ans.size();

            remainder *= 10;
            ans += to_string(remainder / d);
            remainder %= d;
        }

        return ans;
    }
};
