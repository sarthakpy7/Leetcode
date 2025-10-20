#include <vector>
#include <iostream>

class Solution {
private:
    std::vector<std::vector<bool>> visited;
    int m, n;
    const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(std::vector<std::vector<char>>& board, int i, int j) {
        if (visited[i][j]) return;
        visited[i][j] = true;

        for (const auto& dir : directions) {
            int newR = i + dir[0];
            int newC = j + dir[1];

            if (newR >= 0 && newR < m && newC >= 0 && newC < n &&
                board[newR][newC] == 'O' && !visited[newR][newC]) {
                dfs(board, newR, newC);
            }
        }
    }

public:
    void solve(std::vector<std::vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        m = board.size();
        n = board[0].size();
        visited.assign(m, std::vector<bool>(n, false));

        // 1. **Traverse** top and bottom borders
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O' && !visited[0][j]) dfs(board, 0, j);
            if (board[m - 1][j] == 'O' && !visited[m - 1][j]) dfs(board, m - 1, j);
        }

        // 2. **Traverse** left and right borders
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O' && !visited[i][0]) dfs(board, i, 0);
            if (board[i][n - 1] == 'O' && !visited[i][n - 1]) dfs(board, i, n - 1);
        }   

        // 3. **Flip** unvisited 'O's to 'X's
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};