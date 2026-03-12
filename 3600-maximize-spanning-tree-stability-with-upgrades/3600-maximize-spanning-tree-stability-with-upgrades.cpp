class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        /*

        scan all edges  store min str for edge with must is seted to 1
        push maxheap with edge with must is seted to 0
        if (cntSpaNode > k) return -1;
        if (n - 1 - cntSpaNode > k) return -1
        int remain = n - 1 - cntSpaNode;

        while (remain > 0 && !pq.empty())
            if (root(u) == root(v)) continue;
            dsu.union(u, v);
            remain -= 1;
        if (remain > 0) return -1;
        cnt same root must equal n - 1 if not return -1
        return cntSpaNode;
        
        */
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        int cntSpaEdge = 0;
        size_t numEdge = edges.size();
        int curMinEdge = INT_MAX;
        priority_queue<tuple<int,int,int>> maxHeap;
        for (vector<int>& edge: edges) {
            int u = edge[0], v = edge[1], s = edge[2], m = edge[3];
            if (m == 1) {
                curMinEdge = min(curMinEdge, s);
                if (findRoot(u) == findRoot(v)) return -1;
                merge(u, v);
                cntSpaEdge += 1;
            } else {
                maxHeap.push({s, u, v});
            }
        }
        /*
        10 vs 6, k = 1
        20 vs 6 lose 10 vs 12
        */
        int remain = n - 1 - cntSpaEdge;
        priority_queue<int> usedDoubleWeight;
        while (!maxHeap.empty() && remain > 0) {
            auto [s, u, v] = maxHeap.top();
            maxHeap.pop();
            if (findRoot(u) == findRoot(v)) continue;
            if (k > 0) {
                usedDoubleWeight.push(2 * s);
                k -= 1;
            } else {
                if (!usedDoubleWeight.empty() && usedDoubleWeight.top() / 2 > s) {
                    curMinEdge = min(usedDoubleWeight.top() / 2, curMinEdge);
                    usedDoubleWeight.pop();
                    usedDoubleWeight.push(2 * s);
                } else {
                    curMinEdge = min(curMinEdge, s);
                }
            }
            merge(u, v);
            remain -= 1;
            
        }
        int stardardRoot = findRoot(0);
        for (int i = 0; i < n; ++i) {
            if (stardardRoot != findRoot(i)) {
                return -1;
            }
        }
        while (!usedDoubleWeight.empty()) {
            curMinEdge = min(curMinEdge, usedDoubleWeight.top());
            usedDoubleWeight.pop();
        }
        return curMinEdge;
    }
/*
62840 * 2 pop
39867 * 2
*/
private:
    vector<int> parents;
    int findRoot(int x) {
        if (x == parents[x]) return x;
        return parents[x] = findRoot(parents[x]);
    }
    void merge(int u, int v) {
        int ru = findRoot(u), rv = findRoot(v);
        if (ru == rv) return;
        parents[rv] = ru;
    }
};