/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    grid[i][j] is either 0 or 1.
*/

class Solution {
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    bool inside(int x, int y, int n, int m) {
        return x >= 0 and y >= 0 and x < n and y < m;
    }

    int best = 0, curr = 0;
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = true;
        curr++;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (inside(x, y, n, m) and grid[x][y] == 1 and !vis[x][y]) dfs(grid, vis, x, y);
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] and grid[i][j] == 1) {
                    dfs(grid, vis, i, j);
                    best = max(best, curr);
                    curr = 0;
                }
            }
        }

        return best;
    }
};

