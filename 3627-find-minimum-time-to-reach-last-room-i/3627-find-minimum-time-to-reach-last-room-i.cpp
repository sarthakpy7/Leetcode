class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        int dx = 1, dy = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> heap;
        heap.push({0, 0, 0});

        set<pair<int, int>> unseen;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                unseen.insert({i, j});
        
        unseen.erase({0, 0});

        while (!heap.empty()) {
            auto [time, x, y] = heap.top();
            heap.pop();
            
            if (x == m - 1 && y == n - 1) return time;

            for (int i = 0; i < 4; ++i) {
                swap(dx, dy);
                dy = -dy;
                int X = x + dx, Y = y + dy;

                if (unseen.count({X, Y})) {
                    int t = max(time, moveTime[X][Y]) + 1;
                    heap.push({t, X, Y});
                    unseen.erase({X, Y});}
            }
        }
        return -1;}
};