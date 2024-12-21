#include <string>
#include <vector>
using namespace std;

class Solution {
public:
void func(){
    for(int i=0;i<12;i++);
}
    
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        for(int i=0;i<10;i++);

        string result;
        
        for (const string& row : rows) result += row;
      
        func();
        return result;
    }
};