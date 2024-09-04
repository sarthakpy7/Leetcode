class Solution {
public:
    int robotSim(vector<int>& com, vector<vector<int>>& obstacles) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        set<pair<int, int>> uns;
        for (int i = 0; i < obstacles.size(); i++) {
            uns.insert({obstacles[i][0], obstacles[i][1]});
        }
        int x = 0;
        int y = 0;
        int dir = 0;
        int ans = 0;
        for (int i = 0; i < com.size(); i++) {
            if (com[i] < 0) {
                if (com[i] == -1) {
                    if (dir == 3) {
                        dir = 0;
                    } else {
                        dir++;
                    }
                } else {
                    if (dir == 0) {
                        dir = 3;
                    } else {
                        dir--;
                    }
                }
            } else {
                for (int j = 0; j < com[i]; j++) {
                    if (dir == 0) {
                        if (uns.find({x, y + 1}) == uns.end()) {
                            y++;
                        } else {
                            break;
                        }
                    } else if (dir == 1) {
                        if (uns.find({x + 1, y}) == uns.end()) {
                            x++;
                        } else {
                            break;
                        }
                    } else if (dir == 2) {
                        if (uns.find({x, y - 1}) == uns.end()) {
                            y--;
                        } else {
                            break;
                        }
                    } else {
                        if (uns.find({x - 1, y}) == uns.end()) {
                            x--;
                        } else {
                            break;
                        }
                    }
                    ans = max(ans , (x*x + y*y));
                }
            }
        }
        
        return ans;
    }
};